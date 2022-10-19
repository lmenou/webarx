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
      "  Example: webarx --title assommoir Nalcool\n"
      "If you want to say that a word can be contained in the query, write O "
      "in front of the word (for 'Or')\n"
      "  Example: webarx --title assommoir Oeau")(
      "authors,A", po::value<std::vector<std::string>>()->multitoken(),
      "List of authors to search for\n"
      "If you do not want to search for an author, write N in front of the "
      "name of the author\n"
      "  Example: webarx --authors zola Nmauppassant\n"
      "If you want to say that an author may be search for, write O in front "
      "of the word\n"
      "  Example: webarx --authors zola Omauppassant")(
      "abstract,R", po::value<std::vector<std::string>>()->multitoken(),
      "List of words to search for in the resume or abstract\n"
      "If you do not want to search for the word in the abstract, write N in "
      "front of the word\n"
      "  Example: webarx --abstract alcool Ngervaise\n"
      "If you want to say that a word may be present in the abstract, write O "
      "in front of the word\n"
      "  Example: webarx --abstract alcool Ogervaise")(
      "max-results,M", po::value<int>()->default_value(10),
      "Maximum number of results you wish")(
      "ascend,a",
      "Show results in ascending order, i.e, from the oldest to the "
      "most recent\n");

  _desc.add(generic).add(query);

  try {
    store(po::parse_command_line(argc, argv, _desc), _vm);
    notify(_vm);
    _parsed = true;
  } catch (...) {
    _parsed = false;
    return;
  }

  if (_vm.count("help") || argc == 1) {
    _parsed = false;
    return;
  }

  if (_vm.count("version")) {
    std::cout << "webarx 0.1.0\n";
    std::exit(0);
  }
}
