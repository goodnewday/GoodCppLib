#ifndef _UTIL_CONIFG_H_
#define _UTIL_CONIFG_H_

#ifdef __linux__
#define EXPORT   
#else
#define EXPORT  __declspec(dllexport)
#endif

#endif

