#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_set>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/flags/internal/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_format.h"
#include "absl/strings/str_split.h"

#include "worker.h"

ABSL_FLAG (std::string, urls, "", "Comma separated list of URLs to convert");
ABSL_FLAG (
	std::string, docs, "",
	"Comma separated list of PATHs to files to convert, allowed extensions "
	"are: .docx .pptx .xslx .png");

const int WORKERS = 10;

int main (int argc, char* argv[])
{
	absl::ParseCommandLine (argc, argv);

	// get urls

	if (absl::GetFlag (FLAGS_urls) == "" && absl::GetFlag (FLAGS_docs) == "") {
		std::cout << "No urls or docs provided\n";
		return 1;
	}

	std::vector<std::string> urls_vector =
		absl::StrSplit (absl::GetFlag (FLAGS_urls), ",");
	std::vector<std::string> docs_vector =
		absl::StrSplit (absl::GetFlag (FLAGS_docs), ",");

	std::unordered_set<std::string> urls (
		urls_vector.begin (), urls_vector.end ());
	std::unordered_set<std::string> docs (
		docs_vector.begin (), docs_vector.end ());

	// convert internet urls to pdfs

	if (urls.size ()) {
		std::vector<std::thread> workers;

		for (int i = 0; i < WORKERS; i++) {
			workers.emplace_back (std::thread (
				concurrency::worker_item_convertor, i, true, &urls));
		}

		for (auto& worker : workers) {
			worker.join ();
		}
	}

	// convert doc paths to pdfs

	if (docs.size ()) {
		std::vector<std::thread> workers;

		for (int i = 0; i < WORKERS; i++) {
			workers.emplace_back (std::thread (
				concurrency::worker_item_convertor, i, false, &docs));
		}

		for (auto& worker : workers) {
			worker.join ();
		}
	}

	// convert

	return 0;
}
