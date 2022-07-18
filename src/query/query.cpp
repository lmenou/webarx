#include "query.hpp"
#include <iostream>
#include <string>
#include <vector>

#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

// Parse CLI using Boost
void parse_cli(int argc, char *argv[])
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
  };

  if (vm.count("title")) {
    std::vector<std::string> vec = vm["title"].as<std::vector<std::string> >();
    for (auto w : vec) {
      std::cout << w << "\n";
    }
  }

  if (vm.count("authors")) {
    std::vector<std::string> vec = vm["authors"].as<std::vector<std::string> >();
    for (auto w : vec) {
      std::cout << w << "\n";
    }
  }

  if (vm.count("abstract")) {
    std::vector<std::string> vec = vm["abstract"].as<std::vector<std::string> >();
    for (auto w : vec) {
      std::cout << w << "\n";
    }
  }
};

/* Implement the query itself */

void Query::AddSingleOrFirstField(std::string prefix, std::string &field)
{
  std::string query_string = query + prefix + ":" + field;

  query = query_string;
};

void Query::AddAndField(std::string prefix, std::string &field)
{
  std::string query_string = query + "+AND+" + prefix + ":" + field;

  query = query_string;
};
