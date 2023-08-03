#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/flags/internal/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"
#include "absl/strings/str_split.h"

ABSL_FLAG (std::string, urls, "", "Comma separated list of URLs to convert");

int execute (std::string cmd)
{
	FILE* pipe = popen (cmd.c_str (), "r");
	return WEXITSTATUS (pclose (pipe));
}

void url_to_pdf (std::string url)
{
	// file name

	std::regex file_name_exp ("[a-zA-Z0-9\\d\\-\\_\\.]+");

	std::string file_name = std::regex_replace (
		url, file_name_exp, "$&", std::regex_constants::format_no_copy);

	// execute cli chromium

	std::string cmd = absl::StrFormat (
		"chromium --headless --print-to-pdf=%s.pdf %s 2> /dev/null 1> /dev/null", file_name, url);
	auto exit_code = execute (cmd);

	if (exit_code != 0) {
		std::cout << "Couldn't run chromium\n";
	}

	// print info

	std::cout << absl::StrFormat (
		"code %d, url %s, saved as %s.pdf\n", exit_code, url, file_name);
}

int main (int argc, char* argv[])
{
	absl::ParseCommandLine (argc, argv);

	// get urls

	if (absl::GetFlag (FLAGS_urls) == "") {
		std::cout << "No urls provided\n";
		return 1;
	}

	std::vector<std::string> urls =
		absl::StrSplit (absl::GetFlag (FLAGS_urls), ",");

	// generate pdfs

	for (auto url : urls) {
		url_to_pdf (url);
	}

	return 0;
}
