/**
 * @file system.c
 *
 * System class.
 */
#include "process.h"

#include<stdio.h>
#ifdef __linux__
#include <sys/time.h>
#include <sys/resource.h>
#include<unistd.h>
#endif

/**
 * Gets proces execute path.
 *
 * @author Wuxiao
 * @date 2017/1/2
 *
 * @param [in,out] path If non-null, full pathname of the file.
 * @param 		   size The path space size.
 *
 * @return if the function excute success, 0 for success , 1 for failed
 */

int  get_proces_execute_path(char* path, int size)
{
	if (path == NULL)
	{
		return -1;
	}

#ifdef __linux__
	char *exec_name = (char*)malloc(size);
	int is_success = readlink("/proc/self/exe", exec_name, size);

	if (is_success == -1)
	{
		perror("readlink£º");
		return -1;
	}

	char *last = strrchr(exec_name, '/');

	strncpy(path, exec_name, last - exec_name + 1);
#endif

	return 0;
}


