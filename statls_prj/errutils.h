#ifndef __H__ERRUTILS__
#define __H__ERRUTILS__

#include <errno.h>		/* for definition of errno */
#include <stdarg.h>		/* ISO C variable aruments */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 255

void
err_ret(const char *fmt, ...);
void
err_sys(const char *fmt, ...);
void
err_exit(int error, const char *fmt, ...);
void
err_dump(const char *fmt, ...);
void
err_msg(const char *fmt, ...);
void
err_quit(const char *fmt, ...);

#endif
