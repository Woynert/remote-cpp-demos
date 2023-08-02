#ifndef CONFIG_H
#define CONFIG_H

#include "types.h"
#include <vector>

class State
{
  public:
	static std::vector<Music> music_vector;
};

inline std::vector<Music> State::music_vector = {};

#endif
