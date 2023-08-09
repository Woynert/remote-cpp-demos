#include "cli.h"
#include "pdf.h"

int pdf::url_to_pdf (std::string url)
{
	// file name

	std::regex file_name_exp ("[a-zA-Z0-9\\d\\-\\_\\.]+");

	std::string file_name = std::regex_replace (
		url, file_name_exp, "$&", std::regex_constants::format_no_copy);

	// execute cli chromium

	std::string cmd = absl::StrFormat (
		"chromium --headless --print-to-pdf=%s.pdf %s 2> /dev/null 1> "
		"/dev/null",
		file_name, url);
	auto exit_code = execute (cmd);

	if (exit_code != 0) {
		std::cout << "Couldn't run chromium\n";
	}

	// print info

	std::cout << absl::StrFormat (
		"code %d, url %s, saved as %s.pdf\n", exit_code, url, file_name);

	return exit_code;
}
