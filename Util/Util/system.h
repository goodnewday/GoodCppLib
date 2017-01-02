
#ifndef SkySystem_H_
#define SkySystem_H_

#ifdef __linux__
#define EXPORT   
#else
#define EXPORT  __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif

	int  EXPORT  get_cpu_number(int *cpu_number);
	int  EXPORT  set_process_maxfdsize(int fd_size);

#ifdef __cplusplus
}
#endif

#endif
