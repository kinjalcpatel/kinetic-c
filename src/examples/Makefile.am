if ENABLE_TEST
check_PROGRAMS += \
	blocking_flush \
	blocking_put_get \
	setup_teardown \
	blocking_getkeyrange \
	get_key_range \
	write_file_blocking \
	blocking_getnext_getprevious \
	get_nonblocking \
	write_file_blocking_threads \
	blocking_noop \
	write_file_nonblocking \
	blocking_put_delete \
	put_nonblocking

EXAMPLES_CFLAGS = -Wno-deprecated-declarations
EXAMPLES_CPPFLAGS = -I$(top_srcdir)/include
EXAMPLES_LDADD = $(top_builddir)/src/lib/libkinetic-c-client.la

blocking_flush_SOURCES = src/examples/blocking_flush.c
blocking_flush_CFLAGS = $(EXAMPLES_CFLAGS)
blocking_flush_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
blocking_flush_LDADD = $(EXAMPLES_LDADD)

blocking_put_get_SOURCES = src/examples/blocking_put_get.c
blocking_put_get_CFLAGS = $(EXAMPLES_CFLAGS)
blocking_put_get_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
blocking_put_get_LDADD = $(EXAMPLES_LDADD)

setup_teardown_SOURCES = src/examples/setup_teardown.c
setup_teardown_CFLAGS = $(EXAMPLES_CFLAGS)
setup_teardown_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
setup_teardown_LDADD = $(EXAMPLES_LDADD)

blocking_getkeyrange_SOURCES = src/examples/blocking_getkeyrange.c
blocking_getkeyrange_CFLAGS = $(EXAMPLES_CFLAGS)
blocking_getkeyrange_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
blocking_getkeyrange_LDADD = $(EXAMPLES_LDADD)

get_key_range_SOURCES = src/examples/get_key_range.c
get_key_range_CFLAGS = $(EXAMPLES_CFLAGS)
get_key_range_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
get_key_range_LDADD = $(EXAMPLES_LDADD)

write_file_blocking_SOURCES = src/examples/write_file_blocking.c
write_file_blocking_CFLAGS = $(EXAMPLES_CFLAGS)
write_file_blocking_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
write_file_blocking_LDADD = $(EXAMPLES_LDADD)

blocking_getnext_getprevious_SOURCES = src/examples/blocking_getnext_getprevious.c
blocking_getnext_getprevious_CFLAGS = $(EXAMPLES_CFLAGS)
blocking_getnext_getprevious_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
blocking_getnext_getprevious_LDADD = $(EXAMPLES_LDADD)

get_nonblocking_SOURCES = src/examples/get_nonblocking.c
get_nonblocking_CFLAGS = $(EXAMPLES_CFLAGS)
get_nonblocking_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
get_nonblocking_LDADD = $(EXAMPLES_LDADD)

write_file_blocking_threads_SOURCES = src/examples/write_file_blocking_threads.c
write_file_blocking_threads_CFLAGS = $(EXAMPLES_CFLAGS)
write_file_blocking_threads_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
write_file_blocking_threads_LDADD = $(EXAMPLES_LDADD)

blocking_noop_SOURCES = src/examples/blocking_noop.c
blocking_noop_CFLAGS = $(EXAMPLES_CFLAGS)
blocking_noop_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
blocking_noop_LDADD = $(EXAMPLES_LDADD)

write_file_nonblocking_SOURCES = src/examples/write_file_nonblocking.c
write_file_nonblocking_CFLAGS = $(EXAMPLES_CFLAGS)
write_file_nonblocking_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
write_file_nonblocking_LDADD = $(EXAMPLES_LDADD)

blocking_put_delete_SOURCES = src/examples/blocking_put_delete.c
blocking_put_delete_CFLAGS = $(EXAMPLES_CFLAGS)
blocking_put_delete_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
blocking_put_delete_LDADD = $(EXAMPLES_LDADD)

put_nonblocking_SOURCES = src/examples/put_nonblocking.c
put_nonblocking_CFLAGS = $(EXAMPLES_CFLAGS)
put_nonblocking_CPPFLAGS = $(EXAMPLES_CPPFLAGS)
put_nonblocking_LDADD = $(EXAMPLES_LDADD)
endif
