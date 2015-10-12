bin_PROGRAMS = \
	kinetic-c-util \
	kinetic-c-discovery

kinetic_c_util_SOURCES = main.c

kinetic_c_util_CFLAGS = -I$(top_srcdir)/include

kinetic_c_util_LDADD = ../lib/libkinetic-c-client.la

kinetic_c_discovery_SOURCES = discovery.c

kinetic_c_discovery_CFLAGS = -I$(top_srcdir)/include

kinetic_c_discovery_LDADD = $(top_builddir)/src/lib/libkinetic-c-client.la

distclean-local:
	rm -rf Makefile Makefile.in
