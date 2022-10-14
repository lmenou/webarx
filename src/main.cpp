#include "papers.hpp"
#include "query.hpp"
#include "tui.hpp"

int main(int argc, char *argv[]) {
  CliParser cli(argc, argv);

  if (!cli.cliParsed()) {
    std::cout << "Webscrap papers on ArXiv\n\n";
    std::cout << "Usage: webarx [OPTIONS] [ARG]\n";
    std::cout << cli.getDesc();
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
  if (papers.empty()) {
    std::cout << "There is no results for your query, please make a new one.\n";
    return EXIT_SUCCESS;
  }

  TUI tui;
  tui.show(papers);

  return EXIT_SUCCESS;
}
