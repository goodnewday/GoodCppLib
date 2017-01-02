
#ifndef Process_H_
#define Process_H_

#ifdef __linux__
#define EXPORT   
#else
#define EXPORT  __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C"
{
#endif
	
	int  EXPORT  get_proces_execute_path(char* path, int size);

#ifdef __cplusplus
}
#endif

#endif
