#include "query.hpp"
#include <string>

void Query::AddSingleOrFirstField(std::string prefix,
                                  std::string &field) {
  std::string query_string = query + prefix + ":" + field;

  query = query_string;
};

void Query::AddAndField(std::string prefix, std::string &field) {
  std::string query_string = query + "+AND+" + prefix + ":" + field;

  query = query_string;
};
