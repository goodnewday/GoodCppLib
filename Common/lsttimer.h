#ifndef LST_TIMER
#define LST_TIMER
#include<iostream>
#include <time.h>
#include<pthread.h>
using namespace std;

#define BUFFER_SIZE 64
class util_timer;

class util_timer
{
public:
    util_timer() : prev( NULL ), next( NULL ){}

public:
   time_t expire; 
   void (*cb_func)( int );
   int sockfd;
   util_timer* prev;
   util_timer* next;
};

class   OSMutexLocker
{
public:

	OSMutexLocker(pthread_mutex_t *pMutex)  { m_pMutex = pMutex; pthread_mutex_init(pMutex, NULL); Lock(); }
	~OSMutexLocker() { Unlock(); }

	void Lock()         { pthread_mutex_lock(m_pMutex); }
	void Unlock()       { pthread_mutex_unlock(m_pMutex); }

private:

	pthread_mutex_t *m_pMutex;
};

class sort_timer_lst
{
public:
	sort_timer_lst() : head(NULL), tail(NULL) {}
    ~sort_timer_lst()
    {
        util_timer* tmp = head;
        while( tmp )
        {
            head = tmp->next;
            delete tmp;
            tmp = head;
        }
    }
    void add_timer( util_timer* timer,int sec )
	{
		OSMutexLocker autolocker(&mutex);
        if( !timer )
        {
            return;
        }
		timer->expire = time(NULL) +  sec;
        if( !head )
        {
            head = tail = timer;
            return; 
        }

        add_timer( timer );
    }
    void adjust_timer( util_timer* timer,int sec )
	{
		OSMutexLocker autolocker(&mutex);
        if( !timer )
        {
            return;
        }
		timer->expire = time(NULL) +  sec;
    
        if( timer->next == NULL)
        {
            return;
        }

		if( timer != head )
		{
			timer->prev->next = timer->next;
			timer->next->prev = timer->prev;
			add_timer( timer );
		}
		else
		{
			head = head->next;
			head->prev = NULL;
			timer->next = NULL;
			add_timer( timer );
		}
		
        
     
    }
    void del_timer( util_timer* timer )
	{
		OSMutexLocker autolocker(&mutex);
        if( !timer )
        {
            return;
        }
        if( ( timer == head ) && ( timer == tail ) )
        {
            delete timer;
            head = NULL;
            tail = NULL;
            return;
        }
        if( timer == head )
        {
            head = head->next;
            head->prev = NULL;
            delete timer;
            return;
        }
        if( timer == tail )
        {
            tail = tail->prev;
            tail->next = NULL;
            delete timer;
            return;
        }

		timer->prev->next = timer->next;
		timer->next->prev = timer->prev;

        delete timer;
    }
    void tick()
    {
		OSMutexLocker autolocker(&mutex);
        if( !head )
        {
            return;
        }
        time_t cur = time( NULL );
        util_timer* tmp = head;
        while( tmp )
        {
            if( cur < tmp->expire )
            {
                break;
            }
            tmp->cb_func( tmp->sockfd);
            tmp = tmp->next;
        }
    }

private:
    void add_timer( util_timer* timer )
	{
			tail->next = timer;
			timer->prev = tail;
			timer->next = NULL;
			tail = timer;
	} 

private:
    util_timer* head;
    util_timer* tail;
	pthread_mutex_t mutex;
};

#endif
