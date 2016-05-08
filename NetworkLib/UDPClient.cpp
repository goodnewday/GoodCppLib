#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<strings.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <arpa/inet.h>


int UDPClient()
{
	int sock;
	char sendbuf[200] = {"ok"};	
	int  sendlen = 0;
	struct sockaddr_in toAddr;
	struct sockaddr_in fromAddr;

	unsigned int fromLen;
	char recvBuffer[128];
	sock = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);

	if(sock < 0)
	{
		perror("socket:");
		return -1;
	}

	memset(&toAddr,0,sizeof(toAddr));
	toAddr.sin_family=AF_INET;
	toAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	toAddr.sin_port = htons(4000);

	sendlen = strlen(sendbuf);
	if(sendto(sock, sendbuf, sendlen, 0, (struct sockaddr*)&toAddr, sizeof(toAddr)) != sendlen)
	{
		perror("sendto");
		close(sock);
		return -1;
	}

	fromLen = sizeof(fromAddr);
	if(recvfrom(sock,recvBuffer,128,0,(struct sockaddr*)&fromAddr,&fromLen)<0)
	{
		perror("recvfrom");
		close(sock);
		return -1;
	}
	
	close(sock);
}

int main(int argc, char *argv[])
{
	UDPClient();
	
	return -1;
}
