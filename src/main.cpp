#include <iostream>
#include <string>

#include "query/query.hpp"

int main(int argc, char *argv[])
{
  Query q;
  q.Compose(argc, argv);

  std::cout << "The query is:\n" << q << "\n";

  return 0;
}
