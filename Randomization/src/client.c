#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int sock;
  struct sockaddr_in server;

  if ( (sock = socket(AF_INET, SOCK_STREAM,0)) == -1 ){
    perror("Could not create socket\n");
    return(1);
  }

	server.sin_addr.s_addr = inet_addr(argv[1]);
	server.sin_family = AF_INET;
	server.sin_port = htons(atoi(argv[2]));

	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0)
	{
		perror("Could not connect\n");
		return 1;
	}  

  close(sock);

}
