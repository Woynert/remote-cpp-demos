#ifndef CLIENT_H
#define CLIENT_H

#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()

class Client
{
  private:
	int sockfd, connfd;
	struct sockaddr_in servaddr, cli;

  public:
	int try_connect ();
	int disconnect ();
	void loop ();
};

#endif // !CLIENT_H
