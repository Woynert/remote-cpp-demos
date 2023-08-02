#ifndef SERVER_H
#define SERVER_H

#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()

class Server
{
  private:
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

  public:
	int start ();
	int stop ();
	void loop ();
};

#endif // !SERVER_H
