#include "field.hpp"

Field::Field(const std::string prefix, const std::string cliArg) {
  field = prefix;

  const char boolLetter = cliArg[0];
  if (boolLetter == 'N') {
    notField = true;
    for (auto it = cliArg.begin() + 1; it != cliArg.end(); ++it) {
      search.push_back(*it);
    }
  } else {
    search = cliArg;
    notField = false;
  }
}
