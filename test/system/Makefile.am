if ENABLE_TEST
check_PROGRAMS += \
	test_system_async_io             test_system_multi_process \
	test_system_async_throughput     test_system_noop \
	test_system_bus                  test_system_overlapped_io \
	test_system_delete               test_system_p2pop \
	test_system_erase                test_system_p2pop_throughput \
	test_system_fatal_errors         test_system_put \
	test_system_flush                test_system_put_get_delete_mix \
	test_system_get                  test_system_receive_thread \
	test_system_getkeyrange          test_system_security \
	test_system_get_log              test_system_set_cluster_version \
	test_system_getnext_getprevious  test_system_set_pin \
	test_system_idle                 test_system_stress_session_per_thread \
	test_system_lock_unlock          test_system_stress_single_session_threaded \
	test_system_media_scan_optimize

SYSTEM_TEST_CFLAGS = -Werror -Wstrict-prototypes -O3 -DTEST
SYSTEM_TEST_CPPFLAGS = \
        -I$(top_srcdir)/include -I$(top_srcdir)/src/lib \
        -I$(top_srcdir)/src/lib/bus -I$(top_srcdir)/src/lib/threadpool \
	-I$(top_srcdir)/test/support -I@UNITYPATH@/src @CPPFLAGS@

extra_files = $(SYSTEM_TEST_CPPFLAGS) \
	$(top_srcdir)/test/support/system_test_fixture.c \
	$(top_srcdir)/test/support/system_test_kv_generate.c \
	@UNITYPATH@/src/unity.c

SYSTEM_TEST_LDADD = $(top_builddir)/src/lib/libkinetic-c-client.la

test_system_async_io_SOURCES = \
	test-runner/test_system_async_io_runner.c \
	test/system/test_system_async_io.c
test_system_async_io_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_async_io_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_async_io_LDFLAGS = $(extra_files)
test_system_async_io_LDADD = $(SYSTEM_TEST_LDADD)

test_system_async_throughput_SOURCES = \
	test-runner/test_system_async_throughput_runner.c \
	test/system/test_system_async_throughput.c
test_system_async_throughput_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_async_throughput_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_async_throughput_LDFLAGS =  $(extra_files)
test_system_async_throughput_LDADD = $(SYSTEM_TEST_LDADD)

test_system_bus_SOURCES = \
	test-runner/test_system_bus_runner.c \
	test/system/test_system_bus.c
test_system_bus_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_bus_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_bus_LDFLAGS = $(extra_files)
test_system_bus_LDADD = $(SYSTEM_TEST_LDADD)

test_system_delete_SOURCES = \
	test-runner/test_system_delete_runner.c \
	test/system/test_system_delete.c
test_system_delete_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_delete_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_delete_LDFLAGS = $(extra_files)
test_system_delete_LDADD = $(SYSTEM_TEST_LDADD)

test_system_erase_SOURCES = \
	test-runner/test_system_erase_runner.c \
	test/system/test_system_erase.c
test_system_erase_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_erase_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_erase_LDFLAGS = $(extra_files)
test_system_erase_LDADD = $(SYSTEM_TEST_LDADD)

test_system_fatal_errors_SOURCES = \
	test-runner/test_system_fatal_errors_runner.c \
	test/system/test_system_fatal_errors.c
test_system_fatal_errors_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_fatal_errors_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_fatal_errors_LDFLAGS = $(extra_files)
test_system_fatal_errors_LDADD = $(SYSTEM_TEST_LDADD)

test_system_flush_SOURCES = \
	test-runner/test_system_flush_runner.c \
	test/system/test_system_flush.c
test_system_flush_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_flush_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_flush_LDFLAGS = $(extra_files)
test_system_flush_LDADD = $(SYSTEM_TEST_LDADD)

test_system_get_SOURCES = \
	test-runner/test_system_get_runner.c \
	test/system/test_system_get.c
test_system_get_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_get_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_get_LDFLAGS = $(extra_files)
test_system_get_LDADD = $(SYSTEM_TEST_LDADD)

test_system_getkeyrange_SOURCES = \
	test-runner/test_system_getkeyrange_runner.c \
	test/system/test_system_getkeyrange.c
test_system_getkeyrange_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_getkeyrange_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_getkeyrange_LDFLAGS = $(extra_files)
test_system_getkeyrange_LDADD = $(SYSTEM_TEST_LDADD)

test_system_get_log_SOURCES = \
	test-runner/test_system_get_log_runner.c \
	test/system/test_system_get_log.c
test_system_get_log_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_get_log_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_get_log_LDFLAGS = $(extra_files)
test_system_get_log_LDADD = $(SYSTEM_TEST_LDADD)

test_system_getnext_getprevious_SOURCES = \
	test-runner/test_system_getnext_getprevious_runner.c \
	test/system/test_system_getnext_getprevious.c
test_system_getnext_getprevious_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_getnext_getprevious_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_getnext_getprevious_LDFLAGS = $(extra_files)
test_system_getnext_getprevious_LDADD = $(SYSTEM_TEST_LDADD)

test_system_idle_SOURCES = \
	test-runner/test_system_idle_runner.c \
	test/system/test_system_idle.c
test_system_idle_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_idle_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_idle_LDFLAGS = $(extra_files)
test_system_idle_LDADD = $(SYSTEM_TEST_LDADD)

test_system_lock_unlock_SOURCES = \
	test-runner/test_system_lock_unlock_runner.c \
	test/system/test_system_lock_unlock.c
test_system_lock_unlock_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_lock_unlock_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_lock_unlock_LDFLAGS = $(extra_files)
test_system_lock_unlock_LDADD = $(SYSTEM_TEST_LDADD)

test_system_media_scan_optimize_SOURCES = \
	test-runner/test_system_media_scan_optimize_runner.c \
	test/system/test_system_media_scan_optimize.c
test_system_media_scan_optimize_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_media_scan_optimize_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_media_scan_optimize_LDFLAGS = $(extra_files)
test_system_media_scan_optimize_LDADD = $(SYSTEM_TEST_LDADD)

test_system_multi_process_SOURCES = \
	test-runner/test_system_multi_process_runner.c \
	test/system/test_system_multi_process.c
test_system_multi_process_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_multi_process_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_multi_process_LDFLAGS = $(extra_files)
test_system_multi_process_LDADD = $(SYSTEM_TEST_LDADD)

test_system_noop_SOURCES = \
	test-runner/test_system_noop_runner.c \
	test/system/test_system_noop.c
test_system_noop_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_noop_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_noop_LDFLAGS = $(extra_files)
test_system_noop_LDADD = $(SYSTEM_TEST_LDADD)

test_system_overlapped_io_SOURCES = \
	test-runner/test_system_overlapped_io_runner.c \
	test/system/test_system_overlapped_io.c
test_system_overlapped_io_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_overlapped_io_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_overlapped_io_LDFLAGS = $(extra_files)
test_system_overlapped_io_LDADD = $(SYSTEM_TEST_LDADD)

test_system_p2pop_SOURCES = \
	test-runner/test_system_p2pop_runner.c \
	test/system/test_system_p2pop.c
test_system_p2pop_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_p2pop_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_p2pop_LDFLAGS = $(extra_files)
test_system_p2pop_LDADD = $(SYSTEM_TEST_LDADD)

test_system_p2pop_throughput_SOURCES = \
	test-runner/test_system_p2pop_throughput_runner.c \
	test/system/test_system_p2pop_throughput.c
test_system_p2pop_throughput_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_p2pop_throughput_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_p2pop_throughput_LDFLAGS = $(extra_files)
test_system_p2pop_throughput_LDADD = $(SYSTEM_TEST_LDADD)

test_system_put_SOURCES = \
	test-runner/test_system_put_runner.c \
	test/system/test_system_put.c
test_system_put_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_put_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_put_LDFLAGS = $(extra_files)
test_system_put_LDADD = $(SYSTEM_TEST_LDADD)

test_system_put_get_delete_mix_SOURCES = \
	test-runner/test_system_put_get_delete_mix_runner.c \
	test/system/test_system_put_get_delete_mix.c
test_system_put_get_delete_mix_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_put_get_delete_mix_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_put_get_delete_mix_LDFLAGS = $(extra_files)
test_system_put_get_delete_mix_LDADD = $(SYSTEM_TEST_LDADD)

test_system_receive_thread_SOURCES = \
	test-runner/test_system_receive_thread_runner.c \
	test/system/test_system_receive_thread.c
test_system_receive_thread_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_receive_thread_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_receive_thread_LDFLAGS = $(extra_files)
test_system_receive_thread_LDADD = $(SYSTEM_TEST_LDADD)

test_system_security_SOURCES = \
	test-runner/test_system_security_runner.c \
	test/system/test_system_security.c
test_system_security_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_security_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_security_LDFLAGS = $(extra_files)
test_system_security_LDADD = $(SYSTEM_TEST_LDADD)

test_system_set_cluster_version_SOURCES = \
	test-runner/test_system_set_cluster_version_runner.c \
	test/system/test_system_set_cluster_version.c
test_system_set_cluster_version_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_set_cluster_version_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_set_cluster_version_LDFLAGS = $(extra_files)
test_system_set_cluster_version_LDADD = $(SYSTEM_TEST_LDADD)

test_system_set_pin_SOURCES = \
	test-runner/test_system_set_pin_runner.c \
	test/system/test_system_set_pin.c
test_system_set_pin_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_set_pin_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_set_pin_LDFLAGS = $(extra_files)
test_system_set_pin_LDADD = $(SYSTEM_TEST_LDADD)

test_system_stress_session_per_thread_SOURCES = \
	test-runner/test_system_stress_session_per_thread_runner.c \
	test/system/test_system_stress_session_per_thread.c
test_system_stress_session_per_thread_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_stress_session_per_thread_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_stress_session_per_thread_LDFLAGS = $(extra_files)
test_system_stress_session_per_thread_LDADD = $(SYSTEM_TEST_LDADD)

test_system_stress_single_session_threaded_SOURCES = \
	test-runner/test_system_stress_single_session_threaded_runner.c \
	test/system/test_system_stress_single_session_threaded.c
test_system_stress_single_session_threaded_CFLAGS = $(SYSTEM_TEST_CFLAGS)
test_system_stress_single_session_threaded_CPPFLAGS = $(SYSTEM_TEST_CPPFLAGS)
test_system_stress_single_session_threaded_LDFLAGS = $(extra_files)
test_system_stress_single_session_threaded_LDADD = $(SYSTEM_TEST_LDADD)

test-runner/test_system_async_io_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_async_io.c > test-runner/test_system_async_io_runner.c

test-runner/test_system_async_throughput_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_async_throughput.c > test-runner/test_system_async_throughput_runner.c

test-runner/test_system_bus_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_bus.c > test-runner/test_system_bus_runner.c

test-runner/test_system_delete_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_delete.c > test-runner/test_system_delete_runner.c

test-runner/test_system_erase_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_erase.c > test-runner/test_system_erase_runner.c

test-runner/test_system_fatal_errors_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_fatal_errors.c > test-runner/test_system_fatal_errors_runner.c

test-runner/test_system_flush_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_flush.c > test-runner/test_system_flush_runner.c

test-runner/test_system_get_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_get.c > test-runner/test_system_get_runner.c

test-runner/test_system_getkeyrange_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_getkeyrange.c > test-runner/test_system_getkeyrange_runner.c

test-runner/test_system_get_log_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_get_log.c > test-runner/test_system_get_log_runner.c

test-runner/test_system_getnext_getprevious_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_getnext_getprevious.c > test-runner/test_system_getnext_getprevious_runner.c

test-runner/test_system_idle_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_idle.c > test-runner/test_system_idle_runner.c

test-runner/test_system_lock_unlock_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_lock_unlock.c > test-runner/test_system_lock_unlock_runner.c

test-runner/test_system_media_scan_optimize_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_media_scan_optimize.c > test-runner/test_system_media_scan_optimize_runner.c

test-runner/test_system_multi_process_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_multi_process.c > test-runner/test_system_multi_process_runner.c

test-runner/test_system_noop_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_noop.c > test-runner/test_system_noop_runner.c

test-runner/test_system_overlapped_io_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_overlapped_io.c > test-runner/test_system_overlapped_io_runner.c

test-runner/test_system_p2pop_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_p2pop.c > test-runner/test_system_p2pop_runner.c

test-runner/test_system_p2pop_throughput_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_p2pop_throughput.c > test-runner/test_system_p2pop_throughput_runner.c

test-runner/test_system_put_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_put.c > test-runner/test_system_put_runner.c

test-runner/test_system_put_get_delete_mix_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_put_get_delete_mix.c > test-runner/test_system_put_get_delete_mix_runner.c

test-runner/test_system_receive_thread_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_receive_thread.c > test-runner/test_system_receive_thread_runner.c

test-runner/test_system_security_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_security.c > test-runner/test_system_security_runner.c

test-runner/test_system_set_cluster_version_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_set_cluster_version.c > test-runner/test_system_set_cluster_version_runner.c

test-runner/test_system_set_pin_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_set_pin.c > test-runner/test_system_set_pin_runner.c

test-runner/test_system_stress_session_per_thread_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_stress_session_per_thread.c > test-runner/test_system_stress_session_per_thread_runner.c

test-runner/test_system_stress_single_session_threaded_runner.c:
	sh $(top_srcdir)/test/support/generate_test_runner.sh test/system/test_system_stress_single_session_threaded.c > test-runner/test_system_stress_single_session_threaded_runner.c
endif
