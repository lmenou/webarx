#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include "cliparser.hpp"
#include <iostream>
#include <map>

class Query {
private:
  std::string query{};
  std::string response{};
  static const std::string address;
  static const std::map<std::string, std::string> prefixes;
  static const int max_results{300};
  void addField(const std::string prefix, const std::string field);
  std::string findPrefix(const std::map<std::string, std::string> &prefixes,
                         const std::string &cli_prefix);
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
