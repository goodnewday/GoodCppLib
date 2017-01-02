#ifndef _DAEMON_H_
#define _DAEMON_H_

#ifdef __linux__
#define EXPORT   
#else
#define EXPORT  __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

	int  EXPORT glibc_daemon(int nochdir, int noclose);

#ifdef __cplusplus
}
#endif

#endif

