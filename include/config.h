/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Maximum size of file info in message */
#define EL_FLEN_MAX 32

/* Maximum size of file info in message */
#define EL_FUNCLEN_MAX 32

/* Maximum size of single log message */
#define EL_LOG_MAX 8192

/* Number of bytes to print in one line in el_pmemory function */
#define EL_MEM_LINE_SIZE 16

/* Maximum size of prefix */
#define EL_PREFIX_MAX 128

/* Enable printing binary logs */

#define ENABLE_BINARY_LOGS 1

/* Enable using clock() as time source in log */
#define ENABLE_CLOCK 0

/* Enable output colorization */
#define ENABLE_COLORS 1

/* Enable more colors in logs */
/* #undef ENABLE_COLORS_EXTENDED */

/* Enable printing file info with log */
#define ENABLE_FINFO 1

/* Enable printing fractions with log */
#define ENABLE_FRACTIONS 1

/* Enable printing function info with log */
#define ENABLE_FUNCINFO 1

/* Enable using CLOCK_MONOTONIC in log */
#define ENABLE_MONOTONIC 1

/* Enable printing to custom */
#define ENABLE_OUT_CUSTOM 1

/* Enable printing to file */
#define ENABLE_OUT_FILE 1

/* Enable printing to stderr and stdout */
#define ENABLE_OUT_STDERR 1

/* Enable printing to tty */
#define ENABLE_OUT_TTY 0

/* Enable printing prefix to each message */
#define ENABLE_PREFIX 1

/* Enable thread safety measures */
#define ENABLE_PTHREAD 1

/* Enable using CLOCK_REALTIME in log */
#define ENABLE_REALTIME 1

/* Enable reentrant functions */
#define ENABLE_REENTRANT 1

/* Enable printing timestamp with log */
#define ENABLE_TIMESTAMP 1

/* Define to 1 if you have the `access' function. */
#define HAVE_ACCESS 0

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the `fileno' function. */
#define HAVE_FILENO 1

/* Define to 1 if you have the `fsync' function. */
#define HAVE_FSYNC 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define if you have POSIX threads libraries and header files. */
#define HAVE_PTHREAD 1

/* Have PTHREAD_PRIO_INHERIT. */
#define HAVE_PTHREAD_PRIO_INHERIT 1

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF 1

/* Define to 1 if you have the `stat' function. */
#define HAVE_STAT 0

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `symlink' function. */
#define HAVE_SYMLINK 0

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <termios.h> header file. */
#define HAVE_TERMIOS_H 0

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Maximum length of path to open when printing to file */
#define MAX_PATH 4096

/* Library uses only snprintf */
/* #undef NEED_SNPRINTF_ONLY */

/* Name of package */
#define PACKAGE "embedlog"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "michal.lyszczek@bofc.pl"

/* Define to the full name of this package. */
#define PACKAGE_NAME "embedlog"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "embedlog 9999"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "embedlog"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "9999"

/* Use snprintf provided by library */
/* #undef PREFER_PORTABLE_SNPRINTF */

/* Define to necessary symbol if this constant uses a non-standard name on
   your system. */
/* #undef PTHREAD_CREATE_JOINABLE */

/* Enables extra code for testing purposes */
/* #undef RUN_TESTS */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "9999"
