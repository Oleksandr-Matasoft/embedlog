/* ==========================================================================
    Licensed under BSD 2clause license See LICENSE file for more information
    Author: Michał Łyszczek <michal.lyszczek@bofc.pl>
   ==========================================================================
         ----------------------------------------------------------
        / this module deals with initialization and writing to tty \
        \ device                                                   /
         ----------------------------------------------------------
          \            .    .     .
           \      .  . .     `  ,
            \    .; .  : .' :  :  : .
             \   i..`: i` i.i.,i  i .
              \   `,--.|i |i|ii|ii|i:
                   UooU\.'@@@@@@`.||'
                   \__/(@@@@@@@@@@)'
                        (@@@@@@@@)
                        `YY~~~~YY'
                         ||    ||
   ==========================================================================
          _               __            __         ____ _  __
         (_)____   _____ / /__  __ ____/ /___     / __/(_)/ /___   _____
        / // __ \ / ___// // / / // __  // _ \   / /_ / // // _ \ / ___/
       / // / / // /__ / // /_/ // /_/ //  __/  / __// // //  __/(__  )
      /_//_/ /_/ \___//_/ \__,_/ \__,_/ \___/  /_/  /_//_/ \___//____/

   ========================================================================== */


#include "el-private.h"

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#if HAVE_TERMIOS_H
#   include <termios.h>
#endif


/* ==========================================================================
                       __     __ _          ____
        ____   __  __ / /_   / /(_)_____   / __/__  __ ____   _____ _____
       / __ \ / / / // __ \ / // // ___/  / /_ / / / // __ \ / ___// ___/
      / /_/ // /_/ // /_/ // // // /__   / __// /_/ // / / // /__ (__  )
     / .___/ \__,_//_.___//_//_/ \___/  /_/   \__,_//_/ /_/ \___//____/
    /_/
   ========================================================================== */


/* ==========================================================================
    Open tty device and configure it for output only
   ========================================================================== */


int el_tty_open
(
	struct el      *el,    /* store serial file descriptor here */
	const char     *dev,   /* device to open like /dev/ttyS0 */
	unsigned int    speed  /* serial port baud rate */
)
{
	(void) el;
	(void) dev;
	(void) speed;
	// NO tty for sqn embedlog
	return -1;
}


/* ==========================================================================
    Yup, you guessed right - it closes serial.
   ========================================================================== */


int el_tty_close
(
	struct el  *el  /* el object with serial descriptor */
)
{
	VALID(EINVAL, el->serial_fd != -1);

	close(el->serial_fd);
	el->serial_fd = -1;
	return 0;
}


/* ==========================================================================
    Simply sends string pointed by s to serial port configured in el
   ========================================================================== */


int el_tty_puts
(
	struct el   *el,  /* el object with serial descriptor */
	const char  *s    /* string to send */
)
{
	return write(el->serial_fd, s, strlen(s));
}
