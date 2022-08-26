#include "query.hpp"
#include <cpr/cpr.h>

namespace po = boost::program_options;

const std::string Query::address =
    "http://export.arxiv.org/api/query?search_query=";

void Query::addField(std::string prefix, std::string field, std::string andor) {
  query += "+" + andor + "+" + prefix + ":" + field;
};

void Query::prepare() {
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

void Query::compose(CliParser &clip) {
  po::variables_map vm = clip.getCliOptions();
  for (auto v : vm) {
    for (auto w : vm[v.first].as<std::vector<std::string>>()) {
      this->addField(v.first, w, "ANDOR");
    }
  }

  this->prepare();
};

bool Query::fetch() {
  cpr::Url url{query};
  cpr::Response r = cpr::Get(url);

  if (r.status_code == 0) {
    std::cerr << r.error.message << std::endl;
    return false;
  } else if (r.status_code >= 400) {
    std::cerr << "Error [" << r.status_code << "] making request" << std::endl;
    return false;
  } else {
    response = r.text;
  }

  return true;
};
