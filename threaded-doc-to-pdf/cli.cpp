#include "cli.h"

int execute (std::string cmd)
{
	FILE* pipe = popen (cmd.c_str (), "r");
	return WEXITSTATUS (pclose (pipe));
}
