#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<strings.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <arpa/inet.h>

int UDPServer()
{
	int sock;
	struct sockaddr_in toAddr;
	struct sockaddr_in fromAddr;

	int recvLen;
	unsigned int addrLen;
	char recvBuffer[128];

	sock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

	if(sock < 0)
	{
		perror("socket:");
		return -1;
	}

	memset(&fromAddr,0,sizeof(fromAddr));
	fromAddr.sin_family=AF_INET;
	fromAddr.sin_addr.s_addr=htonl(INADDR_ANY);
	fromAddr.sin_port = htons(4000);

	if(bind(sock,(struct sockaddr*)&fromAddr,sizeof(fromAddr))<0)
	{
		perror("bind:");
		close(sock);
		return -1;
	}

	addrLen = sizeof(toAddr);
	if((recvLen = recvfrom(sock,recvBuffer,128,0,(struct sockaddr*)&toAddr,&addrLen))<0)
	{
		perror("recvfrom");
		close(sock);
		return -1;
	}
	if(sendto(sock,recvBuffer,recvLen,0,(struct sockaddr*)&toAddr,sizeof(toAddr))!=recvLen){
		perror("sendto");
		close(sock);
		return -1;
	} 
}


int main(int argc, char *argv[])
{
	UDPServer();
}
