#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include <iostream>
#include <string>

/* Can we do better than that ? */

// Represents the main object to do the api query
class Query {
private:
  std::string query{};
  static const std::string address;

public:
  // Get the query as a string
  std::string getQuery() const { return query; }
  // Utility to construct the query
  void addField(std::string prefix, std::string field, std::string andor);
  // Correct query shape for good query api
  void prepare();
  // Compose the Query itself from cli. Use boost::program_options under the
  // hood.
  void compose(int argc, char *argv[]);
  // Do the request and return the result. Use cpr under the hood.
  std::string fetch() const;

  friend std::ostream &operator<<(std::ostream &os, const Query &q) {
    os << q.query;
    return os;
  }
};

#endif
