#include "pdf.h"
#include "cli.h"

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
		std::cout << "Error running chromium\n";
	}

	return exit_code;
}

int pdf::doc_to_pdf (std::string path)
{
	// execute cli libreoffice

	std::string cmd = absl::StrFormat (
		//"soffice --headless --convert-to pdf --outdir . \"%s\"",
		"soffice --headless --convert-to pdf --outdir . \"%s\" 2> /dev/null 1> "
		"/dev/null",
		path);
	auto exit_code = execute (cmd);

	if (exit_code != 0) {
		std::cout << "Error running soffice: " << cmd << std::endl;
	}

	return exit_code;
}
