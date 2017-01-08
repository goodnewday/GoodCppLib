
#ifndef SkySystem_H_
#define SkySystem_H_

#include "util_config.h"

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
