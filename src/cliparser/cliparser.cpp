#include "cliparser.hpp"
#include <iostream>

CliParser::CliParser(int argc, char *argv[]) {
  // clang-format off
  desc.add_options()
    ("help,h", "Produce help message")
    ("title,T", po::value< std::vector<std::string> >()->multitoken(), "List of words that can be contained in the title\n"
         "If you do not want the word contained, write N in front of the word\n"
         "Example: webarx --title assommoir Nalcool")
    ("authors,A", po::value< std::vector<std::string> >()->multitoken(), "List of authors to search for\n"
         "If you do not want to search for an author, write N in front of the name of the author\n"
         "Example: webarx --authors zola Nmauppassant")
    ("abstract,R", po::value< std::vector<std::string> >()->multitoken(), "List of words to search for in the resume or abstract"
         "If you do not want to search for the word in the abstract, write N in front of the word\n"
         "Example: webarx --abstract alcool Ngervaise");
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
