#ifndef _AUTO_EXEC_TIME_
#define _AUTO_EXEC_TIME_ 

#include <time.h>
#include <string>
using namespace std;

#include"utilplus_config.h"

class CTime;

class  EXPORT CAutoTestTime
{
public:
	CAutoTestTime(const char* function_name);
	~CAutoTestTime();

private:
	void GetStartTime();
	void GetEndTime();
private:
	string      call_function_name_;
	CTime *		time_;
};

#endif

