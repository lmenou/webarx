#include "field.hpp"

Field::Field(const std::string &cliArg) {
  const char boolLetter = cliArg[0];
  if (boolLetter == 'N') {
    booleanOp = "+ANDNOT+";
    for (auto it = cliArg.begin() + 1; it != cliArg.end(); ++it) {
      field.push_back(*it);
    }
  } else {
    booleanOp = "+AND+";
    field = cliArg;
  }
}
