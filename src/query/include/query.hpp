#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include "cliparser.hpp"
#include "field.hpp"
#include <iostream>
#include <map>

class Query {
private:
  std::vector<Field> andField{};
  std::vector<Field> andNotField{};
  std::string response{};
  std::string query{};

  static const std::string address;
  static const std::map<std::string, std::string> prefixes;
  static const int max_results{300};

  std::string findPrefix(const std::map<std::string, std::string> &prefixes,
                         const std::string &cli_prefix);
  void classifyFields(CliParser &clip);
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
