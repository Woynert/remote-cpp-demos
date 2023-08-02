#include <cstring>
#include "type_serializers.h"

#define ul unsigned long

void serialize_music (char** buff, int* cursor, Music* music) 
{
    int c = *cursor;

    // name size

    ul size = music->name.size();
    memcpy(buff + c, &size, sizeof(ul));
    c += sizeof(ul);

    // name content

    memcpy(buff + c, music->name.data(), size);
    c += size;

    // duration

    memcpy(buff + c, &music->duration, sizeof(int));
    c += sizeof(int);

    *cursor = c;
}

void deserialize_music (char** buff, int* cursor, Music* music)
{
    int c = *cursor;

    // name size

    ul size = 0;
    memcpy(&size, buff + c, sizeof(ul));
    c += sizeof(ul);

    // name content

    music->name.resize(size);
    memcpy(&music->name[0], buff + c, size);
    c += size;

    // duration

    memcpy (&music->duration, buff + c, sizeof(int));
    c += sizeof(int);

    *cursor = c;
}
