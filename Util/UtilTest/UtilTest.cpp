#include<iostream>

#include "test_daemon.hpp"
#include "system.h"
#include "os.h"
#include "process.h"


int TEST_get_cpu_number()
{
	int cpu_number = 0;

	if (get_cpu_number(&cpu_number) == 0)
	{
		printf("cpu number = %d\n", cpu_number);
	}

	return 0;
}

int TEST_set_process_maxfdsize()
{
	if (set_process_maxfdsize(65535) == 0)
	{
		printf("set process max fd size success!\n");
	}

	return 0;
}

int Test_get_proces_execute_path()
{
	char path[255] = { 0 };

	if (get_proces_execute_path(path, sizeof(path)) == 0)
	{
		printf("path = %s\n", path);
	}

	return 0;
}

int main()
{

	TEST_get_cpu_number();

	TEST_set_process_maxfdsize();

	//TEST_daemon();

	Test_get_proces_execute_path();

	os_sleep(5);

	return 0;
}
