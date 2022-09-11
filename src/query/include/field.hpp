#ifndef _FIELD_HPP_
#define _FIELD_HPP_

#include <string>

class Field {
private:
  std::string field{};
  std::string booleanOp{};

public:
  Field(const std::string &cliArg);
  std::string getField() const { return field; }
  std::string getBooleanOp() const { return booleanOp; }
};

#endif
