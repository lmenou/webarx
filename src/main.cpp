#include "papers.hpp"
#include "query.hpp"
#include "tui.hpp"

int main(int argc, char *argv[]) {
  CliParser cli(argc, argv);

  if (!cli.cliParsed()) {
    std::cout << "Allowed options to construct a query:" << std::endl;
    std::cout << cli.getDesc() << std::endl;
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
