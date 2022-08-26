// #include "parse/parsing.hpp"
#include "query/query.hpp"

int main(int argc, char *argv[]) {
  CliParser cli(argc, argv);

  Query q;
  if (cli.cliParsed()) {
    q.compose(cli);
  } else {
    return EXIT_FAILURE;
  }

  bool success = q.fetch();
  Response response{};
  if (success) {
    response = q.getResponse();
  } else {
    return EXIT_FAILURE;
  }

  std::cout << response << "\n";

  // ParsedDoc docs;
  // docs.parse(response);
  // docs.screenRenderer();

  return EXIT_SUCCESS;
}
