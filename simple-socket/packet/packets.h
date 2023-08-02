#include <cstdio>
#include <vector>
#include <cstring>

#include "types.h"
#include "type_serializers.h"

class PacketMusic 
{
    public:
        int count;
        std::vector<Music> music_vector;

        static void serialize(char** buff, int* cursor, std::vector<Music> music_vector);
        static PacketMusic* deserialize (char** buff, int* cursor);
};


