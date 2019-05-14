/* ==========================================================================
    Licensed under BSD 2clause license See LICENSE file for more information
    Author: Michał Łyszczek <michal.lyszczek@bofc.pl>
   ==========================================================================

   -----------------------------------------------------------
  / This module handles printing messages with standard errno \
  \ message, no magic to be found here                        /
   -----------------------------------------------------------
         \   ,__,
          \  (oo)____
             (__)    )\
                ||--|| *
   ========================================================================== */


/* ==========================================================================
          _               __            __         ____ _  __
         (_)____   _____ / /__  __ ____/ /___     / __/(_)/ /___   _____
        / // __ \ / ___// // / / // __  // _ \   / /_ / // // _ \ / ___/
       / // / / // /__ / // /_/ // /_/ //  __/  / __// // //  __/(__  )
      /_//_/ /_/ \___//_/ \__,_/ \__,_/ \___/  /_/  /_//_/ \___//____/

   ========================================================================== */


#include "el-private.h"

#include <errno.h>
#include <stdarg.h>
#include <string.h>


/* ==========================================================================
                                   _                __
                     ____   _____ (_)_   __ ____ _ / /_ ___
                    / __ \ / ___// /| | / // __ `// __// _ \
                   / /_/ // /   / / | |/ // /_/ // /_ /  __/
                  / .___//_/   /_/  |___/ \__,_/ \__/ \___/
                 /_/
               ____                     __   _
              / __/__  __ ____   _____ / /_ (_)____   ____   _____
             / /_ / / / // __ \ / ___// __// // __ \ / __ \ / ___/
            / __// /_/ // / / // /__ / /_ / // /_/ // / / /(__  )
           /_/   \__,_//_/ /_/ \___/ \__//_/ \____//_/ /_//____/

   ========================================================================== */


/* ==========================================================================
    calls el_print with 'fmt' and '...' parameters, but  additionaly  prints
    information about errno.  Functionaly it is similar to  perror  function
   ========================================================================== */


static int el_ovperror
(
    const char    *file,   /* file name where log is printed */
    size_t         num,    /* line number where log is printed */
    const char    *func,   /* function name to print */
    enum el_level  level,  /* log level to print message with */
    struct el     *el,     /* el defining printing style */
    const char    *fmt,    /* message format (see printf (3)) */
    va_list        ap      /* additional parameters for fmt */
)
{
    int            rc;     /* return code from el_print() */
    unsigned long  e;      /* errno from upper layer */
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


    VALID(EINVAL, el);

    e = errno;
    rc = 0;

    if (fmt)
    {
        /*
         * we print formatted message only when it is supplied by the user,
         * otherwise only errno message will be printed
         */

        rc |= el_ovprint(file, num, func, level, el, fmt, ap);
    }

    rc |= el_oprint(file, num, func, level, el,
        "errno num: %lu, strerror: %s", e, strerror(e));

    /*
     * in case errno has been modified return it to value from before this
     * call
     */

    errno = e;
    return rc;
}


/* ==========================================================================
                                        __     __ _
                         ____   __  __ / /_   / /(_)_____
                        / __ \ / / / // __ \ / // // ___/
                       / /_/ // /_/ // /_/ // // // /__
                      / .___/ \__,_//_.___//_//_/ \___/
                     /_/
               ____                     __   _
              / __/__  __ ____   _____ / /_ (_)____   ____   _____
             / /_ / / / // __ \ / ___// __// // __ \ / __ \ / ___/
            / __// /_/ // / / // /__ / /_ / // /_/ // / / /(__  )
           /_/   \__,_//_/ /_/ \___/ \__//_/ \____//_/ /_//____/

   ========================================================================== */


/* ==========================================================================
    calls el_print with 'fmt' and '...' parameters, but  additionaly  prints
    information about errno.  Functionaly it is similar to  perror  function
   ========================================================================== */


int el_perror
(
    const char    *file,   /* file name where log is printed */
    size_t         num,    /* line number where log is printed */
    const char    *func,   /* function name to print */
    enum el_level  level,  /* log level to print message with */
    const char    *fmt,    /* message format (see printf (3)) */
                   ...     /* additional parameters for fmt */
)
{
    int            rc;     /* return code from el_operror() */
    va_list        ap;     /* argument pointer for variadic variables */
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


    va_start(ap, fmt);
    rc = el_ovperror(file, num, func, level, &g_el, fmt, ap);
    va_end(ap);

    return rc;
}


/* ==========================================================================
    el_perror function with custom el
   ========================================================================== */


int el_operror
(
    const char    *file,   /* file name where log is printed */
    size_t         num,    /* line number where log is printed*/
    const char    *func,   /* function name to print */
    enum el_level  level,  /* log level to print message with */
    struct el     *el,     /* el defining printing style */
    const char    *fmt,    /* message format (see printf (3)) */
                   ...     /* additional parameters for fmt */
)
{
    int            rc;     /* return code from el_operror() */
    va_list        ap;     /* argument pointer for variadic variables */
    /*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


    va_start(ap, fmt);
    rc = el_ovperror(file, num, func, level, el, fmt, ap);
    va_end(ap);

    return rc;
}
