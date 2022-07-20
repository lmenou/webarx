#include <iostream>
#include <string>

#include "query/query.hpp"

using std::cout;

int main(int argc, char *argv[]) {
  Query q;
  q.Compose(argc, argv);

  cout << "The query is:\n" << q << "\n";

  std::string response  = q.Fetch();
  cout << response << "\n";

  return 0;
}
