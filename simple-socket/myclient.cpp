#include <stdio.h>

#include "client.h"

int main ()
{

	Client* myclient = new Client ();

	// connect

	if (myclient->try_connect () != 0) {
		printf ("Couldn't connect to server\n");
		return 1;
	}

	// enter loop

	myclient->loop ();
	myclient->disconnect ();
	printf ("Exit\n");

	return 0;
}
