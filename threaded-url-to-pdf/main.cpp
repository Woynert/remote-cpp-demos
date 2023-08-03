#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/flags/internal/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_split.h"

ABSL_FLAG (std::string, urls, "", "Comma separated list of URLs to convert");

void execute (std::string cmd)
{
	FILE* pipe = popen (cmd.c_str (), "r");

	if (WEXITSTATUS (pclose (pipe)) != 0) {
		throw std::runtime_error ("Failed to open chromium");
	}
}

int main (int argc, char* argv[])
{
	absl::ParseCommandLine (argc, argv);

	// get urls

	if (absl::GetFlag(FLAGS_urls) == "")
	{
		std::cout << "No urls provided\n";
		return 1;
	}

	std::vector<std::string> urls =
		absl::StrSplit (absl::GetFlag (FLAGS_urls), ",");

	for (auto url : urls)
		std::cout << url << std::endl;

	return 0;
}
