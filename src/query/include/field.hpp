#ifndef _FIELD_HPP_
#define _FIELD_HPP_

#include <string>

class Field {
private:
  std::string search{};
  std::string field{};
  bool notField{};

public:
  Field(const std::string prefix, const std::string cliArg);
  bool isNot() const { return notField; }
  std::string compose() const { return field + ":" + search; }

  friend std::ostream &operator<<(std::ostream &os, const Field &f) {
    std::string repr = f.compose();
    os << repr;
    return os;
  }
};

#endif
