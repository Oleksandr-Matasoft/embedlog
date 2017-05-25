/* ==========================================================================
    Licensed under BSD 2clause license. See LICENSE file for more information
    Author: Michał Łyszczek <michal.lyszczek@bofc.pl>
   ========================================================================== */


#ifndef EMBEDLOG_H
#define EMBEDLOG_H 1

#include <stddef.h>

#define ELE EL_LEVEL_ERR, __FILE__, __LINE__
#define ELW EL_LEVEL_WRN, __FILE__, __LINE__
#define ELI EL_LEVEL_INF, __FILE__, __LINE__
#define ELD EL_LEVEL_DBG, __FILE__, __LINE__


enum el_output
{
    EL_OUT_STDERR = 0x01,
    EL_OUT_SYSLOG = 0x02,
    EL_OUT_FILE   = 0x04,
    EL_OUT_NET    = 0x08,
    EL_OUT_TTY    = 0x10,
    EL_OUT_ALL    = 0x1f
};

enum el_level
{
    EL_LEVEL_ERR,
    EL_LEVEL_WRN,
    EL_LEVEL_INF,
    EL_LEVEL_DBG
};

enum el_option
{
    EL_OPT_COLORS,
    EL_OPT_TS,
    EL_OPT_TS_TM,
    EL_OPT_FINFO,
};

enum el_option_timestamp
{
    EL_OPT_TS_LONG,
    EL_OPT_TS_SHORT,
    EL_OPT_TS_OFF
};

enum el_option_timestamp_timer
{
    EL_OPT_TS_TM_CLOCK,
    EL_OPT_TS_TM_TIME,
    EL_OPT_TS_TM_REALTIME,
    EL_OPT_TS_TM_MONOTONIC
};


int el_level_set(enum el_level);
int el_output_enable(enum el_output);
int el_output_disable(enum el_output);
int el_option(enum el_option, int);
int el_print(enum el_level, const char *, size_t, const char *, ...);
int el_print_mem(enum el_level, const char *, size_t, const void *, size_t);


#endif
