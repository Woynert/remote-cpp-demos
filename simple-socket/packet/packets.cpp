#include <cstdio>
#include <cstring>
#include <vector>

#include "packets.h"
#include "type_serializers.h"
#include "types.h"

void PacketMusic::serialize (
	char** buff, int* cursor, std::vector<Music> music_vector)
{
	int c = *cursor;

	// count

	unsigned long count = music_vector.size ();
	memcpy (buff + c, &count, sizeof (unsigned long));
	c += sizeof (unsigned long);

	// music vector

	Music* music;

	for (int i = 0; i < count; i++) {
		music = &music_vector[i];

		// serialize

		serialize_music (buff, &c, music);
	}

	*cursor = c;
}

PacketMusic* PacketMusic::deserialize (char** buff, int* cursor)
{
	int c = *cursor;

	// count

	unsigned long count = 0;
	memcpy (&count, buff, sizeof (unsigned long));
	c += sizeof (unsigned long);

	// music vector

	Music* music = nullptr;
	PacketMusic* packet = new PacketMusic ();
	packet->count = count;

	for (int i = 0; i < count; i++) {

		// deserialize

		music = new Music ();
		deserialize_music (buff, &c, music);
		printf ("%d music: %s\n", i, music->name.c_str ());

		// append

		// packet->music_vector.push_back(*music);
	}

	*cursor = c;
	return packet;
}
