#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include "../cliparser/cliparser.hpp"
#include "response.hpp"
#include <iostream>

class Query {
private:
  std::string query{};
  Response response{};
  static const std::string address;

public:
  std::string getQuery() const { return query; }
  Response getResponse() const { return response; }
  void addField(std::string prefix, std::string field, std::string andor);
  void prepare();
  void compose(CliParser &clip);
  bool fetch();

  friend std::ostream &operator<<(std::ostream &os, const Query &q) {
    os << q.query;
    return os;
  }
};

#endif
