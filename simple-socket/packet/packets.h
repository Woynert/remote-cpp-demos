#include <cstdio>
#include <cstring>
#include <vector>

#include "type_serializers.h"
#include "types.h"

class PacketMusic
{
  public:
	int count;
	std::vector<Music> music_vector;

	static void
	serialize (char** buff, int* cursor, std::vector<Music> music_vector);
	static PacketMusic* deserialize (char** buff, int* cursor);
};
