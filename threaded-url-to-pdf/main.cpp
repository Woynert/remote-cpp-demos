#include <iostream>
#include <string>
#include <vector>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/strings/str_split.h"

ABSL_FLAG(std::string, urls, "", "Comma separated list of URLs to convert");

int main (int argc, char *argv[])
{
    absl::ParseCommandLine(argc, argv);

    // get urls 

    std::vector<std::string> urls = absl::StrSplit(absl::GetFlag(FLAGS_urls), ",");
    for (auto url: urls)
        std::cout << url << std::endl;


    std::cout << "Hello " << absl::GetFlag(FLAGS_count) << std::endl;
    return 0;
}
