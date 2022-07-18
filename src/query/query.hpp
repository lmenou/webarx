#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include <iostream>
#include <string>

// Represents the main object to manipulate to do the api query
class Query {
 private:
  std::string query;

 public:
  Query()
  {
    query = "http://export.arxiv.org/api/query?search_query=";
  };

  // Get the query as a string
  std::string GetQuery()
  {
    return query;
  };

  friend std::ostream& operator<<(std::ostream& os, const Query& q)
  {
    os << q.query;
    return os;
  };

  // Utility to construct the query
  void AddSingleOrFirstField(std::string prefix, std::string field);
  // Utility to construct the query
  void AddAndField(std::string prefix, std::string field);
};

#endif
