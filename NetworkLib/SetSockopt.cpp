#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/ip.h>


int setsocket_keepalive(int sockfd) 
{    
	int isuccess = 0;
	int keepAlive=1;//开启keepalive属性     
	int keepIdle=3;//如该连接在3秒内没有任何数据往来，则进行探测     
	int keepInterval=2;//探测时发包的时间间隔为2秒     
	int keepCount=3;//探测尝试的次数。如果第1次探测包就收到响应了，则后2次的不再发送     

	isuccess = setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE,(void *)&keepAlive, sizeof(keepAlive));
	if(isuccess != 0)//若无错误发生，setsockopt()返回值为0     
	{         
		perror("setsockopt SO_KEEPALIVE:");
		return isuccess;
	}     

	isuccess = setsockopt(sockfd, IPPROTO_TCP, TCP_KEEPIDLE, (void *)&keepIdle, sizeof(keepIdle));
	if(isuccess != 0)     
	{    
		perror("setsockopt TCP_KEEPIDLE:");    
		return isuccess;
	}    

	isuccess = setsockopt(sockfd, IPPROTO_TCP, TCP_KEEPINTVL, (void *)&keepInterval, sizeof(keepInterval));
	if(isuccess != 0)     
	{         
		perror("setsockopt TCP_KEEPINTVL:"); 
		return isuccess;
	}     

	isuccess = setsockopt(sockfd, IPPROTO_TCP, TCP_KEEPCNT, (void *)&keepCount, sizeof(keepCount));
	if(isuccess != 0)     
	{         
		perror("setsockopt TCP_KEEPCNT:"); 
		return isuccess;
	} 
} 


int setsocket_reuseaddr(int sockfd)
{
	int isuccess = 0;
    int on = 1;
    isuccess = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    if(isuccess != 0)  
    {
        perror("setsockopt SO_REUSEADDR:");
    }

    return isuccess;
}

int setsocket_sndbuf(int sockfd)
{
	int isuccess  = 0;
	int snd_buffsize =1024*1024*8;

	isuccess = setsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, (const char*)&snd_buffsize, sizeof(snd_buffsize));
	if(isuccess != 0)
	{
		perror("setsockopt SO_SNDBUF:");
	}

	return isuccess;
}


int setsocket_rcvbuf(int sockfd)
{
	int isuccess  = 0;
	int rcv_buffsize =1024*1024*8;

	isuccess = setsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, (const char*)&rcv_buffsize, sizeof(rcv_buffsize));
	if(isuccess != 0)
	{
		perror("setsockopt SO_SNDBUF:");
	}

	return isuccess;
}

// The router will process priority, it's change IP Layer option
int setsocket_IP_TOS(int sockfd)
{
	int isuccess = 0;
	unsigned char  service_type = IPTOS_CLASS_CS6;
	
	isuccess = setsockopt(sockfd, SOL_IP/*IPPROTO_IP*/, IP_TOS, (void *)&service_type, sizeof(service_type)); 
	if(isuccess != 0)
	{
		perror("setsockopt IP_TOS:"); 
	}
	
	return isuccess;
}


//The linux kernel will process priority
int setsocket_SO_PRIORITY(int sockfd)
{
	int isuccess = 0;
	int priority = 6;	

	isuccess = setsockopt(sockfd, SOL_SOCKET, SO_PRIORITY, &priority, sizeof(priority));
	if(isuccess != 0)
	{
	 	perror("setsockopt SO_PRIORITY:");
	}

	return isuccess;
}

