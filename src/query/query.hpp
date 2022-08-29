#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include "../cliparser/cliparser.hpp"
#include "response.hpp"
#include <iostream>

typedef std::string Url;

class Query {
private:
  Url query{};
  Response response{};
  static const std::string address;
  void addField(std::string prefix, std::string field, std::string andor);
  void prepare();

public:
  void compose(CliParser &clip);
  Url getQuery() const { return query; }
  Response getResponse() const { return response; }
  bool fetch();

  friend std::ostream &operator<<(std::ostream &os, const Query &q) {
    os << q.query;
    return os;
  }
};

#endif
