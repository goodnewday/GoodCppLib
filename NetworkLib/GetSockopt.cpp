#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

int getsocket_rcvbuf(int sockfd, int *size)
{
	int isuccess  = 0;
	int rcv_buffsize = 0;
	unsigned int len = 0;

	isuccess = getsockopt(sockfd, SOL_SOCKET, SO_RCVBUF, (char*)&rcv_buffsize, &len);
	if(isuccess != 0)
	{
		perror("getsockopt SO_SNDBUF:");
		return isuccess;
	}
	*size = rcv_buffsize;
	return isuccess;
}

int getsocket_sndbuf(int sockfd, int *size)
{
	int isuccess  = 0;
	int snd_buffsize = 0;
	unsigned int len = 0;

	isuccess = getsockopt(sockfd, SOL_SOCKET, SO_SNDBUF, (char*)&snd_buffsize, &len);
	if(isuccess != 0)
	{
		perror("getsockopt SO_SNDBUF:");
		return isuccess;
	}

	*size = snd_buffsize;
	return isuccess;
}


