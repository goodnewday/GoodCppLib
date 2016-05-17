#include <pthread.h>

void *thread_start(void *arg)
{
}

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
	pthread_create(&thread_id, &attr, thread_start, NULL);
	is_success = pthread_create(&thread_id, &attr, &thread_start, NULL);	
	
	pthread_join(thread_id, NULL);
}
