/* ==========================================================================
    Licensed under BSD 2clause license. See LICENSE file for more information
    Author: Michał Łyszczek <michal.lyszczek@bofc.pl>
   ========================================================================== */


#ifndef EMBEDLOG_H
#define EMBEDLOG_H 1

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef NOFINFO
#   define ELF NULL, 0, NULL, EL_FATAL
#   define ELA NULL, 0, NULL, EL_ALERT
#   define ELC NULL, 0, NULL, EL_CRIT
#   define ELE NULL, 0, NULL, EL_ERROR
#   define ELW NULL, 0, NULL, EL_WARN
#   define ELN NULL, 0, NULL, EL_NOTICE
#   define ELI NULL, 0, NULL, EL_INFO
#   define ELD NULL, 0, NULL, EL_DBG

#   define OELF NULL, 0, NULL, EL_FATAL, EL_OPTIONS_OBJECT
#   define OELA NULL, 0, NULL, EL_ALERT, EL_OPTIONS_OBJECT
#   define OELC NULL, 0, NULL, EL_CRIT, EL_OPTIONS_OBJECT
#   define OELE NULL, 0, NULL, EL_ERROR, EL_OPTIONS_OBJECT
#   define OELW NULL, 0, NULL, EL_WARN, EL_OPTIONS_OBJECT
#   define OELN NULL, 0, NULL, EL_NOTICE, EL_OPTIONS_OBJECT
#   define OELI NULL, 0, NULL, EL_INFO, EL_OPTIONS_OBJECT
#   define OELD NULL, 0, NULL, EL_DBG, EL_OPTIONS_OBJECT
#else
#   define ELF __FILE__, __LINE__, EL_FUNC_NAME, EL_FATAL
#   define ELA __FILE__, __LINE__, EL_FUNC_NAME, EL_ALERT
#   define ELC __FILE__, __LINE__, EL_FUNC_NAME, EL_CRIT
#   define ELE __FILE__, __LINE__, EL_FUNC_NAME, EL_ERROR
#   define ELW __FILE__, __LINE__, EL_FUNC_NAME, EL_WARN
#   define ELN __FILE__, __LINE__, EL_FUNC_NAME, EL_NOTICE
#   define ELI __FILE__, __LINE__, EL_FUNC_NAME, EL_INFO
#   define ELD __FILE__, __LINE__, EL_FUNC_NAME, EL_DBG

#   define OELF __FILE__, __LINE__, EL_FUNC_NAME, EL_FATAL, EL_OPTIONS_OBJECT
#   define OELA __FILE__, __LINE__, EL_FUNC_NAME, EL_ALERT, EL_OPTIONS_OBJECT
#   define OELC __FILE__, __LINE__, EL_FUNC_NAME, EL_CRIT, EL_OPTIONS_OBJECT
#   define OELE __FILE__, __LINE__, EL_FUNC_NAME, EL_ERROR, EL_OPTIONS_OBJECT
#   define OELW __FILE__, __LINE__, EL_FUNC_NAME, EL_WARN, EL_OPTIONS_OBJECT
#   define OELN __FILE__, __LINE__, EL_FUNC_NAME, EL_NOTICE, EL_OPTIONS_OBJECT
#   define OELI __FILE__, __LINE__, EL_FUNC_NAME, EL_INFO, EL_OPTIONS_OBJECT
#   define OELD __FILE__, __LINE__, EL_FUNC_NAME, EL_DBG, EL_OPTIONS_OBJECT
#endif

#if (__STDC_VERSION__ >= 199901L)
    /* options for c99 users, they can affort more */
#   define EL_FUNC_NAME __func__
#   ifdef NDEBUG
#       define EL_DEBUG(...) ((void)0)
#   else
#       define EL_DEBUG(...) el_print(ELD, __VA_ARGS__)
#   endif
#else
#   define EL_FUNC_NAME NULL
#endif

/* enum values, new enums can be added, but values of already
 * existing enums *must* stay unchanged, to keep ABI stable!
 */

enum el_output
{
    EL_OUT_NONE   = 0x0000,
    EL_OUT_STDERR = 0x0001,
    EL_OUT_STDOUT = 0x0002,
    EL_OUT_SYSLOG = 0x0004,
    EL_OUT_FILE   = 0x0008,
    EL_OUT_NET    = 0x0010,
    EL_OUT_TTY    = 0x0020,
    EL_OUT_CUSTOM = 0x0040,
    EL_OUT_ALL    = 0x7fff
};

enum el_level
{
    EL_FATAL  = 0,
    EL_ALERT  = 1,
    EL_CRIT   = 2,
    EL_ERROR  = 3,
    EL_WARN   = 4,
    EL_NOTICE = 5,
    EL_INFO   = 6,
    EL_DBG    = 7
};

enum el_option
{
    EL_LEVEL          = 0,
    EL_OUT            = 1,
    EL_COLORS         = 2,
    EL_TS             = 3,
    EL_TS_TM          = 4,
    EL_TS_FRACT       = 5,
    EL_PRINT_LEVEL    = 6,
    EL_PRINT_NL       = 7,
    EL_FINFO          = 8,
    EL_FUNCINFO       = 9,
    EL_CUSTOM_PUTS    = 10,
    EL_TTY_DEV        = 11,
    EL_PREFIX         = 12,

    EL_FPATH          = 13,
    EL_FROTATE_NUMBER = 14,
    EL_FROTATE_SIZE   = 15,
    EL_FSYNC_EVERY    = 16,
    EL_FSYNC_LEVEL    = 17,

    /* internal use only, should represent number of options, if
     * you add option, increment this by one (or by the number of
     * options you add).
     */

    EL_OPT_ERROR      = 18
};

enum el_option_timestamp
{
    EL_TS_OFF   = 0,
    EL_TS_SHORT = 1,
    EL_TS_LONG  = 2,

    /* internal use only, should represent number of options, if
     * you add option, increment this by one (or by the number of
     * options you add).
     */

    EL_TS_ERROR = 3
};

enum el_option_timestamp_timer
{
    EL_TS_TM_TIME      = 0,
    EL_TS_TM_CLOCK     = 1,
    EL_TS_TM_REALTIME  = 2,
    EL_TS_TM_MONOTONIC = 3,

    /* internal use only, should represent number of options, if
     * you add option, increment this by one (or by the number of
     * options you add).
     */

    EL_TS_TM_ERROR     = 4
};

enum el_option_timestamp_fractions
{
    EL_TS_FRACT_OFF   = 0,
    EL_TS_FRACT_MS    = 1,
    EL_TS_FRACT_US    = 2,
    EL_TS_FRACT_NS    = 3,

    /* internal use only, should represent number of options, if
     * you add option, increment this by one (or by the number of
     * options you add).
     */

    EL_TS_FRACT_ERROR = 4
};

typedef int (*el_custom_puts)(const char *s, void *user);

struct el_options
{
    unsigned int    outputs:7;
    unsigned int    colors:1;
    unsigned int    timestamp:2;
    unsigned int    timestamp_timer:3;
    unsigned int    timestamp_fractions:2;
    unsigned int    print_log_level:1;
    unsigned int    print_newline:1;
    unsigned int    finfo:1;
    unsigned int    funcinfo:1;
    unsigned int    level:3;
    unsigned int    level_current_msg:3;
    unsigned int    file_sync_level:3;

    int             serial_fd;
    unsigned int    frotate_number;
    unsigned int    fcurrent_rotate;
    unsigned long   frotate_size;
    unsigned long   file_sync_every;
    unsigned long   written_after_sync;
    unsigned long   fpos;
    FILE           *file;
    char           *current_log;
    const char     *fname;
    const char     *prefix;
    el_custom_puts  custom_puts;
    void           *custom_puts_user;
};

int el_init(void);
int el_cleanup(void);
int el_option(int option, ...);
int el_puts(const char *string);
int el_print(const char *file, size_t line, const char *func,
        enum el_level level, const char *fmt, ...);
int el_vprint(const char *file, size_t line, const char *func,
        enum el_level level, const char *fmt, va_list ap);
int el_pmemory(const char *file, size_t line, const char *func,
        enum el_level level, const void *memory, size_t mlen);
int el_pmemory_table(const char *file, size_t line, const char *func,
        enum el_level level, const void *memory, size_t mlen);
int el_perror(const char *file, size_t line, const char *func,
        enum el_level level, const char *fmt, ...);
int el_putb(const void *memory, size_t mlen);
int el_pbinary(enum el_level level, const void *memory, size_t mlen);
const struct el_options *el_get_options(void);
int el_flush(void);

int el_oinit(struct el_options *options);
int el_ocleanup(struct el_options *options);
int el_ooption(struct el_options *options, int option, ...);
int el_oputs(struct el_options *options, const char *string);
int el_oprint(const char *file, size_t line, const char *func,
        enum el_level level, struct el_options *options, const char *fnt, ...);
int el_ovprint(const char *file, size_t line, const char *func,
        enum el_level level, struct el_options *options, const char *fmt,
        va_list ap);
int el_opmemory(const char *file, size_t line, const char *func,
        enum el_level level, struct el_options *options, const void *memory,
        size_t mlen);
int el_opmemory_table(const char *file, size_t line, const char *func,
        enum el_level level, struct el_options *options, const void *memory,
        size_t mlen);
int el_operror(const char *file, size_t line, const char *func,
        enum el_level level, struct el_options *options, const char *fmt, ...);
int el_oputb(struct el_options *options, const void *memory, size_t mlen);
int el_opbinary(enum el_level level, struct el_options *options,
        const void *memory, size_t mlen);
int el_oflush(struct el_options *options);

#ifdef __cplusplus
}
#endif

#endif
