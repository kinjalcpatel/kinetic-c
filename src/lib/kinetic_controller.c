/*
* kinetic-c
* Copyright (C) 2014 Seagate Technology.
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*
*/

#include "kinetic_controller.h"
#include "kinetic_session.h"
#include "kinetic_operation.h"
#include "kinetic_pdu.h"
#include "kinetic_auth.h"
#include "kinetic_socket.h"
#include "kinetic_allocator.h"
#include "kinetic_logger.h"
#include <pthread.h>
#include "bus.h"

typedef struct {
    pthread_mutex_t receiveCompleteMutex;
    pthread_cond_t receiveComplete;
    KineticStatus status;
} DefaultCallbackData;

static void DefaultCallback(KineticCompletionData* kinetic_data, void* client_data)
{
    DefaultCallbackData * data = client_data;
    data->status = kinetic_data->status;
    pthread_cond_signal(&data->receiveComplete);
}

static KineticCompletionClosure DefaultClosure(DefaultCallbackData * const data)
{
    return (KineticCompletionClosure) {
        .callback = DefaultCallback,
        .clientData = data,
    };
}

KineticStatus KineticController_ExecuteOperation(KineticOperation* operation, KineticCompletionClosure* const closure)
{
    assert(operation != NULL);
    KineticStatus status = KINETIC_STATUS_INVALID;

    LOGF1("Executing operation: %p", operation);
    if (operation->entry != NULL &&
        operation->entry->value.array.data != NULL &&
        operation->entry->value.bytesUsed > 0)
    {
        LOGF1("  Sending PDU (0x%0llX) w/value (%zu bytes)",
            operation->request, operation->entry->value.bytesUsed);
    }
    else {
        LOGF1("  Sending PDU (0x%0llX) w/o value", operation->request);
    }

    if (closure != NULL)
    {
        operation->closure = *closure;
        return KineticOperation_SendRequest(operation);
    }
    else
    {
        DefaultCallbackData data;
        pthread_mutex_init(&data.receiveCompleteMutex, NULL);
        pthread_cond_init(&data.receiveComplete, NULL);
        data.status = KINETIC_STATUS_INVALID;

        operation->closure = DefaultClosure(&data);

        // Send the request
        status = KineticOperation_SendRequest(operation);

        if (status == KINETIC_STATUS_SUCCESS) {
            pthread_mutex_lock(&data.receiveCompleteMutex);
            pthread_cond_wait(&data.receiveComplete, &data.receiveCompleteMutex);
            pthread_mutex_unlock(&data.receiveCompleteMutex);
            status = data.status;
        }

        pthread_cond_destroy(&data.receiveComplete);
        pthread_mutex_destroy(&data.receiveCompleteMutex);

        return status;
    }
}

KineticStatus bus_to_kinetic_status(bus_send_status_t const status)
{
    switch(status)
    {
        // TODO fix all these mappings
        case BUS_SEND_UNDEFINED:
            assert(false);
        case BUS_SEND_SUCCESS:
            return KINETIC_STATUS_SUCCESS;
        case BUS_SEND_TX_TIMEOUT:
            return KINETIC_STATUS_SOCKET_TIMEOUT;
        case BUS_SEND_TX_FAILURE:
            return KINETIC_STATUS_SOCKET_ERROR;
        case BUS_SEND_RX_TIMEOUT:
            return KINETIC_STATUS_OPERATION_TIMEDOUT;
        case BUS_SEND_RX_FAILURE:
            return KINETIC_STATUS_SOCKET_ERROR;
        case BUS_SEND_BAD_RESPONSE:
            return KINETIC_STATUS_SOCKET_ERROR;
    }
}

static const char *bus_error_string(bus_send_status_t t) {
    switch (t) {
    default:
    case BUS_SEND_UNDEFINED:
        return "undefined";
    case BUS_SEND_SUCCESS:
        return "success";
    case BUS_SEND_TX_TIMEOUT:
        return "tx_timeout";
    case BUS_SEND_TX_FAILURE:
        return "tx_failure";
    case BUS_SEND_RX_TIMEOUT:
        return "rx_timeout";
    case BUS_SEND_RX_FAILURE:
        return "rx_failure";
    case BUS_SEND_BAD_RESPONSE:
        return "bad_response";
    }
}

void KineticController_HandleUnexecpectedResponse(void *msg,
                                                  int64_t seq_id,
                                                  void *bus_udata,
                                                  void *socket_udata)
{
    KineticResponse * response = msg;
    KineticConnection* connection = socket_udata;

    (void)seq_id;
    (void)bus_udata;

    KineticLogger_LogProtobuf(3, response->proto);

    // Handle unsolicited status PDUs
    if (response->proto->authType == KINETIC_PROTO_MESSAGE_AUTH_TYPE_UNSOLICITEDSTATUS) {
        if (response->command != NULL &&
            response->command->header != NULL &&
            response->command->header->has_connectionID)
        {
            // Extract connectionID from unsolicited status message
            connection->connectionID = response->command->header->connectionID;
            LOGF2("Extracted connection ID from unsolicited status PDU (id=%lld)",
                connection->connectionID);
        }
        else {
            LOG0("WARNING: Unsolicited PDU in invalid. Does not specify connection ID!");
        }
        KineticAllocator_FreeKineticResponse(response);
    }
    else
    {
        LOG0("WARNING: Received unexpected response that was not an unsolicited status.");
    }
}

void KineticController_HandleExpectedResponse(bus_msg_result_t *res, void *udata)
{
    KineticOperation* op = udata;

    KineticStatus status = bus_to_kinetic_status(res->status);

    if (status == KINETIC_STATUS_SUCCESS) {
        KineticResponse * response = res->u.response.opaque_msg;
        if (response->command != NULL &&
            response->command->status != NULL &&
            response->command->status->has_code)
        {
            status = KineticProtoStatusCode_to_KineticStatus(response->command->status->code);
            LOGF2("Response PDU received w/status %s, %i",
                Kinetic_GetStatusDescription(status), status);
            KineticLogger_LogProtobuf(3, response->proto);
            op->response = response;
        }
        else
        {
            status = KINETIC_STATUS_INVALID;
            LOG0("Error: received a response with a nonexistent command or status");
        }
    }
    else
    {
        // pull out bus error?
        LOGF1("Error receiving response, got message bus error: %s", bus_error_string(res->status));
    }

    // Call operation-specific callback, if configured
    if (op->callback != NULL) {
        status = op->callback(op, status);
    }

    KineticOperation_Complete(op, status);
}

