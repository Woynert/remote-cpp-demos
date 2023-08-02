#include <stdio.h>
#include <vector>

#include "config.h"
#include "packet/types.h"
#include "server.h"

int main ()
{

	// sample music

	std::vector<Music>* music_vector = &Config::music_vector;
	Music* music = nullptr;

	music = new Music ();
	music->name = "Kero Kero Bonito - Flamingo";
	music->duration = 312;
	music_vector->push_back (*music);

	music = new Music ();
	music->name = "Ataquemos - Avena";
	music->duration = 420;
	music_vector->push_back (*music);

	music = new Music ();
	music->name = "Jack Stauber - Cheeseburger family";
	music->duration = 342;
	music_vector->push_back (*music);

	// server

	Server* myserver = new Server ();

	// connect

	if (myserver->start () != 0) {
		printf ("Couldn't start the server");
		return 1;
	}

	// loop

	myserver->loop ();
	myserver->stop ();
	printf ("Exit\n");

	return 0;
}
