
#include"autoexectime.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <ctime>

#ifndef __linux__
#include <windows.h>
#else
#include <unistd.h>
#include<sys/time.h>  
#endif

class CTime
{
public:
	CTime(){}
	~CTime(){}
#ifndef __linux__
	clock_t             start_time_;
	clock_t             end_time_;
#else
	struct timeval      start_time_;
	struct timeval      end_time_;
#endif
};


CAutoTestTime::CAutoTestTime(const char* FuncName) :call_function_name_(FuncName)
{
	time_ = new CTime();
	if (NULL == time_)
	{
		//ScreenPrintf(PRGNAME, "time_ == NULL");
	}
	GetStartTime();
}

CAutoTestTime::~CAutoTestTime()
{
	GetEndTime();

	char buf[128];

#ifndef __linux__	
	sprintf_s(buf, sizeof(buf), "---FuncName:%s--duration:%lf---\n", call_function_name_.c_str(), float(time_->end_time_ - time_->start_time_) / CLK_TCK);
#else
	sprintf(buf,"---FuncName:%s--duration:%u---\n", call_function_name_.c_str(), (time_->end_time_.tv_sec - time_->start_time_.tv_sec) * 1000000 + time_->end_time_.tv_usec - time_->start_time_.tv_usec);
#endif

	printf("%s\n", buf);
}

void CAutoTestTime::GetStartTime()
{
#ifndef __linux__
	time_->start_time_ = clock();
#else
	gettimeofday(&time_->start_time_, NULL);    
#endif
}

void CAutoTestTime::GetEndTime()
{
#ifndef __linux__
	time_->end_time_ = clock();
#else
	gettimeofday(&time_->end_time_, NULL);
#endif

}
