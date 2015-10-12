ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = autogen.sh DEVELOP.md LICENSE Rakefile README.md RELEASE.md Gemfile Gemfile.lock kinetic-c.sublime-project README.autotools

SUBDIRS = src/lib src/utility

if ENABLE_TEST
check_PROGRAMS =

include src/examples/Makefile.am
include test/system/Makefile.am

TESTS = $(check_PROGRAMS)
endif

distclean-local:
	rm -rf autom4te.cache m4 test-runner
	rm -rf aclocal.m4 ar-lib compile config.guess config.h config.h.in config.h.in~ config.status config.sub configure depcomp install-sh libtool ltmain.sh Makefile.in missing stamp-h1 test-driver

.PHONY: start_sims
start_sims:
	sh $(top_srcdir)/scripts/startSimulators.sh

.PHONY: stop_sims
stop_sims:
	sh $(top_srcdir)/scripts/stopSimulators.sh

if ENABLE_TEST
test_internals:
	cd $(top_srcdir)/src/lib/threadpool && make test

KINETIC_HOST1 ?= localhost
UTIL_EXEC = $(top_srcdir)/src/utility/kinetic-c-util

run: all
	@echo
	@echo --------------------------------------------------------------------------------
	@echo Running test utility: $(UTIL_EXEC)
	@echo --------------------------------------------------------------------------------
	@echo
	exec $(UTIL_EXEC) --help
	@echo
	exec $(UTIL_EXEC) -?
	@echo
	exec $(UTIL_EXEC) --noop --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --put --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --put --key goo --value Goodbye! --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --get --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getnext --key A --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getnext --key foo --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getprevious --key zoo --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getprevious --key goo --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --delete --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getlog --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getlog --logtype utilizations --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getlog --logtype temperatures --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getlog --logtype capacities --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getlog --logtype configuration --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getlog --logtype statistics --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getlog --logtype messages --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getlog --logtype limits --host $(KINETIC_HOST1)
	@echo
	exec $(UTIL_EXEC) --getdevicespecificlog --devicelogname com.Seagate --host $(KINETIC_HOST1)
	@echo
	@echo Test Utility integration tests w/ kinetic-c lib passed!
	@echo

test: Rakefile all
	@echo Testing $(PACKAGE)
	bundle install
	bundle exec rake test:delta PROTOBUFCPATH=@PROTOBUFCPATH@ KINETICPROTOPATH=@KINETICPROTOPATH@ SOCKET99PATH=@SOCKET99PATH@

check-local: test_internals run

endif
