/**
 * @file os.c
 *
 * Operating system class. Let use no different between Windows And Linux
 */

#include "daemon.h"

#ifdef __linux__
#include <unistd.h>
#else
#include <Windows.h>
#endif

/**
 * Operating system sleep.
 *
 * @author Wuxiao
 * @date 2017/1/2
 *
 * @param sleep_time The sleep time(second).
 *
 * @return An EXPORT.
 */

int  EXPORT os_sleep(int sleep_time)
{
#ifdef __linux__
	sleep(sleep_time);
#else
	Sleep(sleep_time*1000);
	return 0;
#endif
}

/**
 * Operating system usleep.
 *
 * @author Wuxiao
 * @date 2017/1/2
 *
 * @param usleep_time The usleep time(micro second).
 *
 * @return An EXPORT.
 */

int  EXPORT os_usleep(int usleep_time)
{
#ifdef __linux__
	usleep(usleep_time);
#else
	Sleep(usleep_time / 1000);
	return 0;
#endif
}

