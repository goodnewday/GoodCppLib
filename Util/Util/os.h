#ifndef _OS_H_
#define _OS_H_

#ifdef __linux__
#define EXPORT   
#else
#define EXPORT  __declspec(dllexport)
#endif

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

