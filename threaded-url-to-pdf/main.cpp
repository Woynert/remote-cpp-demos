#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>
#include <vector>
#include <unordered_set>

#include "absl/flags/flag.h"
#include "absl/flags/internal/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"
#include "absl/strings/str_split.h"

#include "pdf.h"

ABSL_FLAG (std::string, urls, "", "Comma separated list of URLs to convert");

int main (int argc, char* argv[])
{
	absl::ParseCommandLine (argc, argv);

	// get urls

	if (absl::GetFlag (FLAGS_urls) == "") {
		std::cout << "No urls provided\n";
		return 1;
	}

	std::vector<std::string> urls_vector =
		absl::StrSplit (absl::GetFlag (FLAGS_urls), ",");

	std::unordered_set<std::string> urls (urls_vector.begin(), urls_vector.end());

	// generate pdfs

	for (auto url : urls) {
		pdf::url_to_pdf (url);
	}

	return 0;
}
