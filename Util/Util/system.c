/**
 * @file system.c
 *
 * System class.
 */
#include "system.h"

#include<stdio.h>
#ifdef __linux__
#include <sys/time.h>
#include <sys/resource.h>
#include<unistd.h>
#endif

/**
 * Gets CPU number.
 *
 * @author Wuxiao
 * @date 2017/1/2
 *
 * @param [in,out] cpu_number If non-null, the CPU number.
 *
 * @return The CPU number.
 */

int get_cpu_number(int *cpu_number)
{
	if (cpu_number == NULL){
		return -1;
	}
	int number = 0;

#ifdef __linux__
	number = sysconf(_SC_NPROCESSORS_CONF);

	*cpu_number = number;

	return 0;
#else
	*cpu_number = 4;

	return 0;
#endif	
}

/**
 * Sets process maxfdsize.
 *
 * @author Wuxiao
 * @date 2017/1/2
 *
 * @param fd_size Size of the fd.
 *
 * @return An int.
 */

int set_process_maxfdsize(int fd_size)
{

#ifdef __linux__
	struct rlimit rt;
	rt.rlim_max = rt.rlim_cur = fd_size;
	if (setrlimit(RLIMIT_NOFILE, &rt) == -1)
	{
		perror("setrlimit faild:");
			return -1;
	}
	else
	{
		return 0;
	}
#endif

	return 0;
}


