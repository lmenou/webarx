// #include "parse/parsing.hpp"
#include "query/query.hpp"

int main(int argc, char *argv[]) {
  CliParser cli(argc, argv);

  if (cli.cliParsed()) {
    Query q;
    q.compose(cli);
    std::cout << q << "\n";
  } else {
    return EXIT_FAILURE;
  }

  // std::string response = q.fetch();

  // ParsedDoc docs;
  // docs.parse(response);
  // docs.screenRenderer();

  return EXIT_SUCCESS;
}
