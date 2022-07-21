#include <iostream>
#include <string>

#include "parse/parsing.hpp"
#include "query/query.hpp"

using std::cout;

int main(int argc, char *argv[]) {
  Query q;
  q.Compose(argc, argv);

  cout << "The query is:\n" << q << "\n";

  std::string response = q.Fetch();
  std::vector<Parseditem> result = parse(response);

  for (auto &res : result) {
    cout << res.title << "\n";
    for (auto &auth : res.authors) {
      cout << auth << "\n";
    }
  }

  return 0;
}
