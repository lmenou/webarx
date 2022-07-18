#include <iostream>
#include <string>

#include "query/cli.hpp"
#include "query/query.hpp"

int main(int argc, char *argv[])
{
  Query q;
  compose_query(argc, argv, q);

  std::cout << "The query is:\n" << q << "\n";

  return 0;
}
