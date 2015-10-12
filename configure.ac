#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([kinetic-c-client], m4_esyscmd_s([head -n1 config/VERSION]), [kve-dev@taec.toshiba.com])
AC_CONFIG_SRCDIR([Makefile.am])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
m4_ifdef([AM_PROG_AR], [AM_PROG_AR])
AM_PROG_CC_C_O
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AM_PROG_LIBTOOL

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h inttypes.h limits.h netdb.h netinet/in.h stddef.h stdint.h stdlib.h string.h], [], AC_MSG_ERROR(cannot find header file))
AC_CHECK_HEADERS([sys/file.h sys/ioctl.h sys/param.h sys/socket.h sys/time.h unistd.h],[], AC_MSG_ERROR(cannot find header file))

AC_CHECK_HEADERS([protobuf-c/protobuf-c.h],[], AC_MSG_ERROR(cannot find protobuf-c headers at default include path please provide it as ./configure CPPFLAGS="-I<path to protobuf-c headers>"))
AC_CHECK_HEADERS([json-c/json.h],[], AC_MSG_ERROR(cannot find json-c headers at default include path please provide it as ./configure CPPFLAGS="-I<path to json-c headers>"))
AC_CHECK_HEADERS([socket99.h],[], AC_MSG_ERROR(cannot find socket99 headers at default include path please provide it as ./configure CPPFLAGS="-I<path to socket99 headers>"))
AC_CHECK_HEADERS([kinetic/kinetic.pb-c.h],[], AC_MSG_ERROR(cannot find kinetic-protocol headers at default include path please provide it as ./configure CPPFLAGS="-I<path to kinetic protocol headers>"))

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_C_INLINE
AC_C_RESTRICT
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_SIZE_T
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([clock_gettime strerror gettimeofday memset])

# Checks for libraries.
AC_CHECK_LIB([pthread], [pthread_cond_init], [LIBS="-lpthread $LIBS"],
	AC_MSG_ERROR(Can not find libpthread implementing pthread_cond_init() function.))

AC_CHECK_LIB([protobuf-c], [protobuf_c_message_pack], [LIBS="-lprotobuf-c $LIBS"],
	AC_MSG_ERROR(Can not find libprotobuf-c implementing protobuf_c_message_pack() function.))

AC_CHECK_LIB([json-c], [json_tokener_new], [LIBS="-ljson-c $LIBS"],
	AC_MSG_ERROR(Can not find libjson-c implementing json_tokener_new() function.))

AC_CHECK_LIB([socket99], [socket99_open], [LIBS="-lsocket99 $LIBS"],
	AC_MSG_ERROR(Can not find libsocket99 implementing socket99_open() function.))

AC_CHECK_LIB([kinetic.pb-c], [com__seagate__kinetic__proto__command__init], [LIBS="-lkinetic.pb-c $LIBS"],
	AC_MSG_ERROR(Can not find libkinetic.pb-c implementing com__seagate__kinetic__proto__command__init() function.))

AC_CHECK_LIB([ssl], [SSL_library_init], [LIBS="-lssl $LIBS"],
	AC_MSG_ERROR(Can not find libssl implementing SSL_library_init() function.))

AC_ARG_ENABLE(test,
        [AS_HELP_STRING([--enable-test[[=ARG]]],[enable building system test targets [ARG=yes]])],
        enable_test=$enableval, enable_test=yes)
if test "$enable_test" = "yes"; then
	AC_PATH_PROG(BUNDLER, bundle, not-found)
	AS_IF([test "$BUNDLER" = "not-found"], [AC_MSG_ERROR(cannot find bundler in $PATH)])

	BUNDLER_VERSION=`$BUNDLER --version | awk '{ print $3}'`
	AC_MSG_CHECKING([is bundler version >= 1.3.5])
	AS_VERSION_COMPARE(${BUNDLER_VERSION}, 1.3.5, [RESULT=-1], [RESULT=0], [RESULT=1])
	AS_IF([test "${RESULT}" != "-1"], AC_MSG_RESULT([found bundler $BUNDLER_VERSION]),
		AC_MSG_ERROR([found bundler v$BUNDLER_VERSION needed v1.3.5 or higher]))

	AC_CONFIG_COMMANDS([mkdir test-runner])

	AC_ARG_VAR([UNITYPATH],
		[path to Unity pacakge for unit testing (only used with --enable-test)])
	AC_CHECK_FILES([${UNITYPATH}/src/unity.h ${UNITYPATH}/src/unity.c], [],
		[AC_MSG_ERROR(cannot find unity unit testing package at "${UNITYPATH}" please provide them as ./configure UNITYPATH="<path to unity package>")])

	AC_ARG_VAR([PROTOBUFCPATH],
                [path to protobuf-c headers for unit testing (only used with --enable-test)])
	if test "${PROTOBUFCPATH}" = ""; then
		AC_SUBST(PROTOBUFCPATH, [/usr/include])
	fi
	AC_CHECK_FILES([${PROTOBUFCPATH}/protobuf-c/protobuf-c.h], [],
		[AC_MSG_ERROR(cannot find protobuf-c headers at "${PROTOBUFCPATH}/protobuf-c" please provide them as ./configure PROTOBUFCPATH="<path to protobuf-c headers>")])

	AC_ARG_VAR([KINETICPROTOPATH],
                [path to kinetic-protocol headers  for unit testing (only used with --enable-test)])
        if test "${KINETICPROTOPATH}" = ""; then
		AC_SUBST(KINETICPROTOPATH, [/usr/include])
        fi
        AC_CHECK_FILES([${KINETICPROTOPATH}/kinetic/kinetic.pb-c.h], [],
                [AC_MSG_ERROR(cannot find kinetic-protocol headers at "${KINETICPROTOPATH}/kinetic" please provide them as ./configure KINETICPROTOPATH="<path to kinetic-protocol headers>")])

	AC_ARG_VAR([SOCKET99PATH],
                [path to socket99 headers for unit testing (only used with --enable-test)])
        if test "${SOCKET99PATH}" = ""; then
		AC_SUBST(SOCKET99PATH, [/usr/include])
        fi
        AC_CHECK_FILES([${SOCKET99PATH}/socket99.h], [],
                [AC_MSG_ERROR(cannot find socket99 headers at "${SOCKET99PATH}" please provide them as ./configure SOCKET99PATH="<path to protobuf-c headers>")])

	AC_TYPE_INT8_T
	AC_TYPE_PID_T

	AC_CHECK_FUNCS([getcwd socket strstr strtol])
	AC_FUNC_ERROR_AT_LINE
	AC_FUNC_FORK

	AC_CHECK_LIB([crypto], [SHA1], [LIBS="-lcrypto $LIBS"],
        	AC_MSG_ERROR(Can not find libcrypto implementing SHA1() function.))
	
fi
AM_CONDITIONAL([ENABLE_TEST], [test x$enable_test = xyes])

AC_CONFIG_FILES([Makefile src/lib/Makefile src/utility/Makefile])

CFLAGS="-Wall -Wextra -Wcast-align -pedantic -Wno-missing-field-initializers \
	-D_POSIX_C_SOURCE=199309L -D_C99_SOURCE=1 -std=c99 -fPIC -g ${CFLAGS}"

AC_OUTPUT

AC_MSG_RESULT([
	$PACKAGE-$VERSION

	CC:                     ${CC}
	CPP:                    ${CPP}
	CFLAGS:                 ${CFLAGS}
	CPPFLAGS:               ${CPPFLAGS}
	LDFLAGS:                ${LDFLAGS}
	LIBS:                   ${LIBS}
	UNITYPATH:		${UNITYPATH}
	PROTOBUFCPATH:		${PROTOBUFCPATH}
	KINETICPROTOPATH:	${KINETICPROTOPATH}
	SOCKET99PATH:		${SOCKET99PATH}

	prefix:                 ${prefix}
	exec_prefix:            ${exec_prefix}
	libdir:                 ${libdir}
	includedir:             ${includedir}
	bindir:                 ${bindir}
])
