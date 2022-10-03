#include "cliparser.hpp"
#include <iostream>

CliParser::CliParser(int argc, char *argv[]) {

  po::options_description generic("General information on the CLI");
  generic.add_options()("help,h", "Produce help message");
  generic.add_options()("version,v", "Show version number");

  po::options_description query("Allowed options to construct a query");
  query.add_options()(
      "title,T", po::value<std::vector<std::string>>()->multitoken(),
      "List of words that can be contained in the title\n"
      "If you do not want the word contained, write N in front of the word\n"
      "  Example: webarx --title assommoir Nalcool")(
      "authors,A", po::value<std::vector<std::string>>()->multitoken(),
      "List of authors to search for\n"
      "If you do not want to search for an author, write N in front of the "
      "name of the author\n"
      "  Example: webarx --authors zola Nmauppassant")(
      "abstract,R", po::value<std::vector<std::string>>()->multitoken(),
      "List of words to search for in the resume or abstract\n"
      "If you do not want to search for the word in the abstract, write N in "
      "front of the word\n"
      "  Example: webarx --abstract alcool Ngervaise")(
      "max-results,M", po::value<int>()->default_value(300),
      "Maximum number of results you wish")(
      "ascend,a", "Show results in ascending order, i.e, from the oldest to the "
                "most recent\n");

  desc.add(generic).add(query);

  try {
    store(po::parse_command_line(argc, argv, desc), vm);
    notify(vm);
    parsed = true;
  } catch (...) {
    parsed = false;
    return;
  }

  if (vm.count("help") || argc == 1) {
    parsed = false;
    return;
  }

  if (vm.count("version")) {
    std::cout << "webarx 0.1.0\n";
    std::exit(0);
  }
}
