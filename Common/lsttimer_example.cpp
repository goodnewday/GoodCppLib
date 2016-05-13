#include <stdio.h>
#include <unistd.h>
#include "lsttimer.h"

//单一时间定时器,所有定时任务同样的时间间隔

#define LIFETIME 5
sort_timer_lst  g_timer_lst;


void HandleTimeOut(int sockfd)
{
	//CGlobalData::GetInstance()->m_NetworkFactory.m_pNetwork->CloseSocket(sockfd);
	printf("Time Out,Will Close Socket\n");
}


void AddTimer(int Socket)
{

	util_timer  *timerNode = NULL;


	timerNode = new util_timer;
	timerNode->sockfd = Socket;	
	timerNode->cb_func = HandleTimeOut;
	g_timer_lst.add_timer(timerNode,LIFETIME);
//	m_liveMap.insert(map<int, util_timer  *>::value_type(Socket, timerNode));
	
}

void AdjustTimer(int Socket)
{

	//m_csFac.m_pCS->RdLock();

	util_timer  *timerNode = NULL;
	//map<int, util_timer  *>::iterator iter;


//iter = m_liveMap.find(Socket);


	//if (m_liveMap.end() != iter)
	{
	//	timerNode = iter->second;

		g_timer_lst.adjust_timer(timerNode,LIFETIME);

	}
	
	//m_csFac.m_pCS->RWUnLock();
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
//		CGlobalData::GetInstance()->GetTimeInterface()->SleepFun(5);
		sleep(5);
	}
}



int main()
{
	AddTimer(1);
	RunTimer(NULL);
	
	sleep(10);
}