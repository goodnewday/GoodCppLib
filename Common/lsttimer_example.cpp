#include <stdio.h>
#include <unistd.h>
#include<map>
#include<mutex>

#include "lsttimer.h"

// g++ lsttimer_example.cpp lsttimer.h -std=c++11
//单一时间定时器,所有定时任务同样的时间间隔

#define LIFETIME 30
sort_timer_lst  g_timer_lst;
map<int, util_timer  *> g_task_map;
mutex                 g_task_map_lock;


void HandleTimeOut(int sockfd)
{
	printf("Time Out,Will Close Socket\n");
}


void AddTimer(int Socket)
{

	util_timer  *timerNode = NULL;


	timerNode = new util_timer;
	timerNode->sockfd = Socket;	
	timerNode->cb_func = HandleTimeOut;
	g_timer_lst.add_timer(timerNode,LIFETIME);
	
	g_task_map_lock.lock();
	g_task_map.insert(map<int, util_timer  *>::value_type(Socket, timerNode));
	g_task_map_lock.unlock();

}

void AdjustTimer(int Socket)
{	
	util_timer  *timerNode = NULL;
	map<int, util_timer  *>::iterator iter;

	g_task_map_lock.lock();
	iter = g_task_map.find(Socket);


	if (g_task_map.end() != iter)
	{
		timerNode = iter->second;

		g_timer_lst.adjust_timer(timerNode, LIFETIME);

	}	
	g_task_map_lock.unlock();

}

void DelTimer(util_timer  *timerNode)
{
	g_timer_lst.del_timer(timerNode);
}

void RunTimer(void *pParam)
{

	while (1)
	{
		g_timer_lst.tick();
		usleep(10);
	}
}



int main()
{
	int i = 0;
	
	for(i = 0; i < 100; i++)
	{
		AddTimer(i);
		usleep(100);
	}
	
	RunTimer(NULL);
	
	sleep(10);
}