#ifndef _QUERY_HPP_
#define _QUERY_HPP_

#include <string>
#include <boost/program_options/options_description.hpp>

namespace po = boost::program_options;

// Parse the cli itself
void parse_cli(int arc, char *argv[]);

// Represents the main object to manipulate to do the api query
class Query {
private:
  std::string query;

public:
  Query() {query = "http://export.arxiv.org/api/query?search_query=";};

  std::string GetQuery() { return query; };
  void AddSingleOrFirstField(std::string prefix, std::string &field);
  void AddAndField(std::string prefix, std::string &field);
};


#endif
