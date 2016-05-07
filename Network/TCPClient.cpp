#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<strings.h>
#include<stdio.h>

void TCPClient()
{
	int             listenfd;
	const int        on = 1;
	struct sockaddr_in hints;
	char buf[100] = {"0sdfsdfsd"};
	int ret = 0;

	bzero(&hints, sizeof(struct sockaddr_in));
	hints.sin_addr.s_addr = INADDR_ANY;
	hints.sin_family = AF_INET;
	hints.sin_port = htons(8899);
	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
	if (connect(listenfd, (struct sockaddr*)&hints, sizeof( struct sockaddr_in)) != 0) {
		printf(" connect fail\n");
	}

	ret = send(listenfd, buf, 100,0);

}

int main()
{
	TCPClient();

	return 0;
}

