
#include "daemon.h"

#ifdef __linux__
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#endif

int DoWorkRun()
{
#ifdef __linux__
	while(1)
	{
		usleep(6000000);
	}
#endif

	return 0;
}

int TEST_daemon()
{
#ifdef __linux__
	pid_t pid;
	int   status = 0;


	if (daemon(0, 1) != 0)
	{
		exit(-1);
	}


	while (1)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork() error:");
			break;
		}

		if (pid == 0)
		{
			DoWorkRun();			
			return 0;
		}


		if (pid > 0)
		{
			do{
				pid = wait(&status);

				if (pid == -1 && status == 0) // parent woken up by a handled signal
				{
					perror("handled signal continue waiting\n");
					continue;
				}
				else
				{
					fprintf(stdout, "wait return\n");
					sleep(1);//wait system clean up 
					break;
				}

			} while (1);
		}

	}
#endif

	return 0;
}
