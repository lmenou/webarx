#include "papers/papers.hpp"
#include "query/query.hpp"

int main(int argc, char *argv[]) {
  CliParser cli(argc, argv);

  if (!cli.cliParsed()) {
    return EXIT_FAILURE;
  }
  Query q(cli);

  bool success = q.fetch();
  if (!success) {
    return EXIT_FAILURE;
  }

  std::string response = q.getResponse();
  Papers papers(response);

  return EXIT_SUCCESS;
}
