#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include "../cliparser/cliparser.hpp"
#include <iostream>
#include <string>

class Query {
private:
  std::string query{};
  static const std::string address;

public:
  std::string getQuery() const { return query; }
  void addField(std::string prefix, std::string field, std::string andor);
  void prepare();
  void compose(CliParser &clip);
  std::string fetch() const;

  friend std::ostream &operator<<(std::ostream &os, const Query &q) {
    os << q.query;
    return os;
  }
};

#endif
