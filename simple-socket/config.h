#ifndef CONFIG_H
#define CONFIG_H

#include <vector>

#include "packet/types.h"

class Config
{
  public:
	static int buff_max;
	static int port;
	static std::vector<Music> music_vector;
};

inline int Config::buff_max = 5000;
inline int Config::port = 8082;
inline std::vector<Music> Config::music_vector = {};

#endif
