#ifndef _OS_H_
#define _OS_H_

#include "util_config.h"

#ifdef __cplusplus
extern "C"
{
#endif

	int  EXPORT os_sleep(int sleep_time);
	int  EXPORT os_usleep(int usleep_time);

#ifdef __cplusplus
}
#endif

#endif

