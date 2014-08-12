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
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*
*/

#include "kinetic_api.h"
#include "kinetic_connection.h"
#include "kinetic_pdu.h"
#include "kinetic_logger.h"
#include <stdio.h>

void KineticApi_Init(const char* logFile)
{
    KineticLogger_Init(logFile);
}

bool KineticApi_Connect(
    KineticConnection* connection,
    const char* host,
    int port,
    bool blocking)
{
    KineticConnection_Init(connection);

    if (!KineticConnection_Connect(connection, host, port, blocking))
    {
        connection->connected = false;
        connection->socketDescriptor = -1;
        char message[64];
        sprintf(message, "Failed creating connection to %s:%d", host, port);
        LOG(message);
        return false;
    }

    connection->connected = true;

    return true;
}

bool KineticApi_ConfigureExchange(
    KineticExchange* exchange,
    KineticConnection* connection,
    int64_t clusterVersion,
    int64_t identity,
    const char* key,
    size_t keyLength)
{
    if (exchange == NULL)
    {
        LOG("Specified KineticExchange is NULL!");
        return false;
    }

    if (key == NULL)
    {
        LOG("Specified Kinetic Protocol key is NULL!");
        return false;
    }

    if (keyLength == 0)
    {
        LOG("Specified Kinetic Protocol key length is NULL!");
        return false;
    }

    KineticExchange_Init(exchange, identity, key, keyLength, connection);
    KineticExchange_SetClusterVersion(exchange, clusterVersion);
    KineticExchange_ConfigureConnectionID(exchange);

    return true;
}

KineticOperation KineticApi_CreateOperation(
    KineticExchange* exchange,
    KineticPDU* request,
    KineticMessage* requestMsg,
    KineticPDU* response)
{
    KineticOperation op;

    if (exchange == NULL)
    {
        LOG("Specified KineticExchange is NULL!");
        assert(exchange != NULL);
    }

    if (request == NULL)
    {
        LOG("Specified request KineticPDU is NULL!");
        assert(request != NULL);
    }

    if (requestMsg == NULL)
    {
        LOG("Specified request KineticMessage is NULL!");
        assert(requestMsg != NULL);
    }

    if (response == NULL)
    {
        LOG("Specified response KineticPDU is NULL!");
        assert(response != NULL);
    }

    KineticMessage_Init(requestMsg);
    KineticPDU_Init(request, exchange, requestMsg, NULL, 0);

    // KineticMessage_Init(responseMsg);
    KineticPDU_Init(response, exchange, NULL, NULL, 0);

    op.exchange = exchange;
    op.request = request;
    op.request->message = requestMsg;
    op.response = response;
    op.response->message = NULL;
    op.response->proto = NULL;

    return op;
}

KineticProto_Status_StatusCode KineticApi_NoOp(KineticOperation* operation)
{
    KineticProto_Status_StatusCode status =
        KINETIC_PROTO_STATUS_STATUS_CODE_INVALID_STATUS_CODE;

    assert(operation->exchange != NULL);
    assert(operation->exchange->connection != NULL);
    assert(operation->request != NULL);
    assert(operation->request->message != NULL);
    assert(operation->response != NULL);
    assert(operation->response->message == NULL);

    // Initialize request
    KineticExchange_IncrementSequence(operation->exchange);
    KineticOperation_BuildNoop(operation);

    // Send the request
    KineticPDU_Send(operation->request);

    // Associate response with same exchange as request
    operation->response->exchange = operation->request->exchange;

    // Receive the response
    if (KineticPDU_Receive(operation->response))
    {
        status = operation->response->proto->command->status->code;
    }

	return status;
}

KineticProto_Status_StatusCode KineticApi_Put(
    KineticOperation* operation,
    uint8_t* value,
    int64_t len)
{
    KineticProto_Status_StatusCode status =
        KINETIC_PROTO_STATUS_STATUS_CODE_INVALID_STATUS_CODE;

    assert(operation->exchange != NULL);
    assert(operation->exchange->connection != NULL);
    assert(operation->request != NULL);
    assert(operation->request->message != NULL);
    assert(operation->response != NULL);
    assert(operation->response->message == NULL);
    assert(value != NULL);
    assert(len < 1024*1024);

    // TODO: Make it happen!!!

    return status;
}
