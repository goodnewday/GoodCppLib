#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <strings.h>
#include <stdio.h>


int TCPServer()
{
	int   listenfd, connfd;
	struct sockaddr_in  cliaddr;

	socklen_t    clilen = sizeof( struct sockaddr_in);
	struct sockaddr_in hints;
	char buf[500] = {0};

	bzero(&hints, sizeof(struct sockaddr_in));
	hints.sin_addr.s_addr =  INADDR_ANY;
	hints.sin_family = AF_INET;
	hints.sin_port = htons(8899);
	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	if (bind(listenfd, (struct sockaddr*)&hints, sizeof( struct sockaddr_in)) != 0) {
		printf(" bind fail\n");
	}
	listen(listenfd, 10);
	connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen);

	int ret = 0;
	ret = recv(connfd, buf, 500, 0);
	printf("buf = %s\n", buf);

	return 0;
}

int main()
{
	TCPServer();

	return 0;
}
