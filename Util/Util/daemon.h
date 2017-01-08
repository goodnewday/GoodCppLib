#ifndef _DAEMON_H_
#define _DAEMON_H_

#include "util_config.h"

#ifdef __cplusplus
extern "C"
{
#endif

	int  EXPORT glibc_daemon(int nochdir, int noclose);

#ifdef __cplusplus
}
#endif

#endif

