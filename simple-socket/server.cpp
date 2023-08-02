#include <cstring>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h> // read(), write(), close()

#include "config.h"
#include "packet/packets.h"
#include "server.h"

int Server::start ()
{
	// socket

	sockfd = socket (AF_INET, SOCK_STREAM, 0);

	if (sockfd == -1) {
		printf ("socket creation failed\n");
		return 1;
	}

	memset (&servaddr, 0, sizeof (servaddr));

	// ip, port

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl (INADDR_ANY);
	servaddr.sin_port = htons (Config::port);

	// bind socket to ip

	int bind_res =
		bind (sockfd, (struct sockaddr*)&servaddr, sizeof (servaddr));

	if (bind_res != 0) {
		printf ("socket bind failed\n");
		return 1;
	}

	// listen for client

	if (listen (sockfd, 5) != 0) {
		printf ("listen failed\n");
		return 1;
	}
	len = sizeof (cli);

	// client data packet (initial?)

	connfd = accept (sockfd, (struct sockaddr*)&cli, (socklen_t*)&len);
	if (connfd < 0) {
		printf ("server accept failed\n");
		return 1;
	}

	return 0;
}

int Server::stop () { return close (sockfd); }

void Server::loop ()
{
	char buff[Config::buff_max];
	int cursor = 0;

	// chat loop

	while (true) {

		// receive

		memset (buff, 0, Config::buff_max);
		read (connfd, buff, sizeof (buff));
		printf ("From client: %s\n", buff);

		// exit

		if (strncmp ("exit", buff, 4) == 0) {
			printf ("Server Exit...\n");
			break;
		}

		// data

		if (strncmp ("data", buff, 4) == 0) {

			// reset

			cursor = 0;
			memset (buff, 0, Config::buff_max);

			// serialize

			PacketMusic::serialize (
				(char**)buff, &cursor, Config::music_vector);

			// send

			printf ("Sending data....\n");
			write (connfd, buff, sizeof (buff));
		}
	}
}

// send data

// void send_data
