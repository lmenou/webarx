#include "query.hpp"

#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>
#include <cpr/cpr.h>

namespace po = boost::program_options;

// All query must start with this address
const std::string Query::address =
    "http://export.arxiv.org/api/query?search_query=";

void Query::AddField(std::string prefix, std::string field, std::string andor) {
  query += "+" + andor + "+" + prefix + ":" + field;
};

void Query::Prepare() {
  std::string::size_type n = 0;
  query = query.substr(1);

  n = query.find("+");
  if (n == std::string::npos) {
    std::cout << "Wrong construct for query, report error..."
              << "\n";
    exit(-1);
  } else {
    query = query.substr(n + 1);
  }

  query = address + query;
};

void Query::Compose(int argc, char *argv[]) {
  // clang-format off
  po::options_description desc("Allowed options to construct a query");
  desc.add_options()
    ("help,h", "Produce help message")
    ("ti,T", po::value< std::vector<std::string> >()->multitoken(), "List of words that can be contained in the title")
    ("au,A", po::value< std::vector<std::string> >()->multitoken(), "List of authors to search for")
    ("abs,R", po::value< std::vector<std::string> >()->multitoken(), "List of words to search for in the resume or abstract");
  // clang-format on

  po::variables_map vm;
  store(po::parse_command_line(argc, argv, desc), vm);
  notify(vm);

  if (vm.count("help") || argc == 1) {
    std::cout << desc << "\n";
    return;
  }

  // TODO: Not elegant, I do not know how to make this in C++17...
  for (auto v : vm) {
    for (auto w : vm[v.first].as<std::vector<std::string>>()) {
      this->AddField(v.first, w, "ANDOR");
    }
  }

  this->Prepare();
};

std::string Query::Fetch() {
  cpr::Url url{query};
  cpr::Response r = cpr::Get(url);

  return r.text;
};
