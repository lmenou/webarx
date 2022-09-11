#include "query.hpp"
#include <cpr/cpr.h>

namespace po = boost::program_options;

const std::string Query::address{
    "http://export.arxiv.org/api/query?search_query="};

const std::map<std::string, std::string> Query::prefixes = {
    {"title", "ti"},
    {"authors", "au"},
    {"abstract", "abs"},
};

std::string
Query::findPrefix(const std::map<std::string, std::string> &prefixes,
                  const std::string &cli_prefix) {
  auto pos = prefixes.find(cli_prefix);
  if (pos != prefixes.end()) {
    return pos->second;
  } else {
    std::cerr
        << "Ill formed cli prefixes, please report the error to the developer"
        << "\n";
    std::exit(1);
  }
};

void Query::addField(const std::string prefix, const Field &field) {
  query += field.getBooleanOp() + prefix + ":" + field.getField();
};

void Query::prepare() {
  std::string::size_type n = 0;
  query = query.substr(1);

  n = query.find("+");
  if (n == std::string::npos) {
    std::cerr << "Wrong construct for query, please report the error to the "
                 "developer"
              << "\n";
    std::exit(1);
  } else {
    query = query.substr(n + 1);
  }

  query = address + query;
  query += "&start=0&max_results=" + std::to_string(max_results);
  query += "&sortBy=lastUpdatedDate&sortOrder=descending";
};

Query::Query(CliParser &clip) {
  po::variables_map vm = clip.getCliOptions();
  for (auto v : vm) {
    for (auto w : vm[v.first].as<std::vector<std::string>>()) {
      Field field(w);
      addField(findPrefix(prefixes, v.first), field);
    }
  }

  prepare();
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
