#include <pthread.h>

int setattr_detach(pthread_attr_t *p_attr)
{
	pthread_attr_init(p_attr);
	pthread_attr_setdetachstate(p_attr, PTHREAD_CREATE_DETACHED);
}

int main()
{
	int 			is_success = 0;
	pthread_t 		thread_id;	
	pthread_attr_t 	attr;
	
	setattr_detach(&attr);
	pthread_create(&thread_id, &attr, &thread_start, (void*)tmp_param);
	is_success = pthread_create(&thread_id, &attr, &thread_start, (void*)tmp_param);	
	
	pthread_join(tid,NULL);
}
