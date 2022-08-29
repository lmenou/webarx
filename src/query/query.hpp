#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include "../cliparser/cliparser.hpp"
#include <iostream>

class Query {
private:
  std::string query{};
  std::string response{};
  static const std::string address;
  void addField(std::string prefix, std::string field, std::string andor);
  void prepare();

public:
  Query(CliParser &clip);
  std::string getQuery() const { return query; }
  std::string getResponse() const { return response; }
  bool fetch();

  friend std::ostream &operator<<(std::ostream &os, const Query &q) {
    os << q.query;
    return os;
  }
};

#endif
