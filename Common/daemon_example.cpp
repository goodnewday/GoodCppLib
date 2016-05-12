#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include "daemon.h"

int test_daemon()
{
	pid_t pid;
	int   status = 0;


	if (daemon(0,1) != 0)	
	{		
		exit(-1);	
	}	


	while(1)	
	{  	
		pid = fork(); 		
		if (pid == -1) 		
		{		
			perror("fork() error:");			
			break;	
		}	

		if (pid == 0) 
		{	
			//do real work
			usleep(6000000);
			return 0;
		}


		if(pid > 0) 				
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

			}while(1);
		}

	} 
}

int main()
{
	test_daemon();
}
