#ifndef _UTIL_CONIFG_H_
#define _UTIL_CONIFG_H_


/*------------------------------------------------------Config------------------------------------------------------------------------------------*/

#define HAS_SCREENPRINTF	 1         /* if open , ScreenPrintf will print to the screen */
#define AUTO_TEST_TIME       1		  /*  if open , use  'AUTO_PRINT_TIME' will print function use time*/




/*------------------------------------------------------Macro definition------------------------------------------------------------------------------------*/
#ifdef __linux__
	#define EXPORT   
#else
	#define EXPORT  __declspec(dllexport)
#endif

#if HAS_SCREENPRINTF
	#define ScreenPrintf(PrgNameStr,ErrorStr) { printf("%s:%s:%d:%s:ErrorInfo:%s\n",PrgNameStr, __FILE__, __LINE__, __FUNCTION__,ErrorStr);}
#else
	#define ScreenPrintf(PrgNameStr,ErrorStr) {;}
#endif

#ifdef AUTO_TEST_TIME
	#define AUTO_PRINT_TIME CAutoTestTime autoTestTime(__FUNCTION__);            
#else
	#define AUTO_PRINT_TIME
#endif

#endif

