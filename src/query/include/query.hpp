#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include "cliparser.hpp"
#include <iostream>
#include <map>
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

class Query {
private:
  std::vector<Field> andField{};
  std::vector<Field> andNotField{};
  std::string response{};
  std::string query{};
  int max_results{};

  static const std::map<std::string, std::string> prefixes;

  void classifyFields(CliParser &clip);
  void prepare();

public:
  static const std::string address;
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
