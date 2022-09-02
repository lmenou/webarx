#include "papers/papers.hpp"
#include "query/query.hpp"
#include "tui/tui.hpp"

int main(int argc, char *argv[]) {
  CliParser cli(argc, argv);

  if (!cli.cliParsed()) {
    std::cout << "It seems that the CLI was misused... Printing the help."
              << "\n";
    return EXIT_SUCCESS;
  }
  Query q(cli);

  bool success = q.fetch();
  if (!success) {
    std::cerr
        << "Fetching did not succeed... please check your network connection."
        << "\n";
    return EXIT_SUCCESS;
  }

  std::string response = q.getResponse();

  Papers papers(response);

  TUI tui;
  tui.show(papers);

  return EXIT_SUCCESS;
}
