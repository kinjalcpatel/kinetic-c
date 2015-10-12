lib_LTLIBRARIES = libkinetic-c-client.la

libkinetic_c_client_includedir = $(includedir)/kinetic
libkinetic_c_client_include_HEADERS = \
	$(top_srcdir)/include/byte_array.h \
	$(top_srcdir)/include/kinetic_client.h \
	$(top_srcdir)/include/kinetic_types.h \
	$(top_srcdir)/include/kinetic_admin_client.h \
	$(top_srcdir)/include/kinetic_semaphore.h

libkinetic_c_client_la_CFLAGS = \
	-Werror=strict-prototypes -Wshadow \
	-I$(top_srcdir)/src/lib/bus -I$(top_srcdir)/src/lib/threadpool \
	-I$(top_srcdir)/include -I$(top_srcdir)/src/lib

libkinetic_c_client_la_LDFLAGS = -release @PACKAGE_VERSION@ @LDFLAGS@

libkinetic_c_client_la_SOURCES = \
        kinetic_allocator.c \
        kinetic_nbo.c \
        kinetic_operation.c \
        kinetic_callbacks.c \
        kinetic_builder.c \
        kinetic_request.c \
        kinetic_response.c \
        kinetic_bus.c \
        kinetic_auth.c \
        kinetic_pdu_unpack.c \
        kinetic_socket.c \
        kinetic_message.c \
        kinetic_logger.c \
        kinetic_hmac.c \
        kinetic_controller.c \
        kinetic_device_info.c \
        kinetic_session.c \
        kinetic_types_internal.c \
        kinetic_types.c \
        kinetic_memory.c \
        kinetic_semaphore.c \
        kinetic_countingsemaphore.c \
        kinetic_resourcewaiter.c \
        kinetic_acl.c \
        byte_array.c \
        kinetic_client.c \
        kinetic_admin_client.c \
        threadpool/threadpool.c \
        bus/bus.c \
        bus/bus_poll.c \
        bus/bus_ssl.c \
        bus/listener.c \
        bus/listener_cmd.c \
        bus/listener_helper.c \
        bus/listener_io.c \
        bus/listener_task.c \
        bus/send.c \
        bus/send_helper.c \
        bus/syscall.c \
        bus/util.c \
        bus/yacht.c

distclean-local:
	rm -rf Makefile Makefile.in
