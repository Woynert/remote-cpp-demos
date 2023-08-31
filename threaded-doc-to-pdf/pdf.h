#ifndef PDF_H
#define PDF_H

#include "absl/strings/str_format.h"
#include <iostream>
#include <regex>
#include <string>

namespace pdf {

int url_to_pdf (std::string url);
int doc_to_pdf (std::string path);

} // namespace pdf

#endif // !PDF_H
