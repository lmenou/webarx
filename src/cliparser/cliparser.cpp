#include "cliparser.hpp"
#include <iostream>

CliParser::CliParser(int argc, char *argv[]) {
  // clang-format off
  desc.add_options()
    ("help,h", "Produce help message")
    ("title,T", po::value< std::vector<std::string> >()->multitoken(), "List of words that can be contained in the title")
    ("authors,A", po::value< std::vector<std::string> >()->multitoken(), "List of authors to search for")
    ("abstract,R", po::value< std::vector<std::string> >()->multitoken(), "List of words to search for in the resume or abstract");
  // clang-format on

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
}
