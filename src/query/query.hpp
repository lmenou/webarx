#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include <iostream>
#include <string>

// Represents the main object to do the api query
class Query {
private:
  std::string query;
  static const std::string address;

public:
  Query(){};

  // Get the query as a string
  std::string GetQuery() { return query; };
  // Utility to construct the query
  void AddField(std::string prefix, std::string field, std::string andor);
  // Correct query shape for good query api
  void Prepare();
  // Compose the Query itself from cli. Use boost::program_options under the
  // hood.
  void Compose(int argc, char *argv[]);
  // Do the request and return the result. Use cpr under the hood.
  std::string Fetch();

  friend std::ostream &operator<<(std::ostream &os, const Query &q) {
    os << q.query;
    return os;
  };
};

#endif
