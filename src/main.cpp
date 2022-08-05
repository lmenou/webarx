#include <iostream>
#include <string>

#include "parse/parsing.hpp"
#include "query/query.hpp"

int main(int argc, char *argv[]) {
  Query q;
  q.compose(argc, argv);

  std::string response = q.fetch();

  ParsedDoc docs;
  docs.parse(response);

  std::cout << docs;

  return EXIT_SUCCESS;
}
