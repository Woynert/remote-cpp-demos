#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()

#include "client.h"
#include "config.h"
#include "packet/packets.h"

int Client::try_connect ()
{
	// socket

	sockfd = socket (AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf ("socket creation failed\n");
		return 1;
	}

	memset (&servaddr, 0, sizeof (servaddr));

	// assing ip, port

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr ("127.0.0.1");
	servaddr.sin_port = htons (Config::port);

	// connect

	if (connect (sockfd, (struct sockaddr*)&servaddr, sizeof (servaddr)) != 0) {
		printf ("connection with server failed\n");
	}

	return 0;
}

int Client::disconnect () { return close (sockfd); }

void Client::loop ()
{
	char buff[Config::buff_max];
	int cursor = 0;
	int n;
	int c;

	while (true) {

		memset (buff, 0, Config::buff_max);

		// input

		printf ("To server: ");

		n = 0;
		c = '\n';

		while ((c = getchar ()) != '\n' && c != EOF) {
			if (n >= Config::buff_max - 1) {

				// flush input buffer
				while ((c = getchar ()) != '\n' && c != EOF) {
				}

				break;
			}

			buff[n++] = c;
		}

		// send

		write (sockfd, buff, sizeof (buff));

		// exit

		if (strncmp (buff, "exit", 4) == 0) {
			printf ("Client exit\n");
			break;
		}

		// data

		if (strncmp ("data", buff, 4) == 0) {

			// reset

			cursor = 0;
			memset (buff, 0, Config::buff_max);

			// receive

			read (sockfd, buff, sizeof (buff));

			// deserialize

			PacketMusic::deserialize ((char**)buff, &cursor);
		}
	}
}
