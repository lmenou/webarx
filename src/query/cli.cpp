#include "cli.hpp"
#include <iostream>

#include <boost/program_options/parsers.hpp>

// TODO: Improve the algorithm

// Compose the query with the argument of the CLI
// The function use boost under the hood.
void compose_query(int argc, char *argv[], Query &q)
{
  // clang-format off
  po::options_description desc("Allowed options to construct a query");
  desc.add_options()
    ("help,h", "Produce help message")
    ("title,T", po::value< std::vector<std::string> >()->multitoken(), "List of words that can be contained in the title")
    ("authors,A", po::value< std::vector<std::string> >()->multitoken(), "List of authors to search for")
    ("abstract,R", po::value< std::vector<std::string> >()->multitoken(), "List of words to search for in the resume or abstract");
  // clang-format on

  po::variables_map vm;
  store(po::parse_command_line(argc, argv, desc), vm);
  notify(vm);

  if (vm.count("help") || argc == 1) {
    std::cout << desc << "\n";
    return;
  }

  int i = 0;
  for (auto v : vm) {
    for (auto w : vm[v.first].as<std::vector<std::string> >()) {
      if (i == 0) {
        q.AddSingleOrFirstField(v.first, w);
        i = 1;
        continue;
      }
      q.AddAndField(v.first, w);
    }
  }
};
