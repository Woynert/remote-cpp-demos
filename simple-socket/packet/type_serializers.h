#ifndef TYPE_SERIALIZERS_H
#define TYPE_SERIALIZERS_H

#include "types.h"

void serialize_music (char** buff, int* cursor, Music* music);
void deserialize_music (char** buff, int* cursor, Music* music);

#endif

