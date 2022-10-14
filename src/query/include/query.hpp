#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include "cliparser.hpp"
#include <iostream>
#include <map>
#include <string>

namespace QueryUtil {
bool isupper(char ch);
};

class Field {
private:
  std::string _search;
  std::string _field;
  char _fType{'a'};

public:
  Field(const std::string prefix, const std::string cliArg);
  char fieldType() const { return _fType; }
  std::string compose() const { return _field + ":" + _search; }

  friend std::ostream &operator<<(std::ostream &os, const Field &f) {
    std::string repr = f.compose();
    os << repr;
    return os;
  }
};

class Query {
private:
  std::vector<Field> _andField;
  std::vector<Field> _andNotField;
  std::vector<Field> _andOrField;
  std::string _response;
  std::string _query;
  int _max_results;
  std::string _sorting;

  static const std::map<std::string, std::string> _prefixes;

  void make(CliParser &clip);
  void prepare();

public:
  static const std::string address;
  Query(CliParser &clip);
  std::string getQuery() const { return _query; }
  std::string getResponse() const { return _response; }
  bool fetch();

  friend std::ostream &operator<<(std::ostream &os, const Query &q) {
    os << q._query;
    return os;
  }
};

#endif
