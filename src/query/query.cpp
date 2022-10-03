#include "query.hpp"
#include <cpr/cpr.h>

Field::Field(const std::string prefix, const std::string cliArg) {
  field = prefix;

  const char boolLetter = cliArg[0];
  if (boolLetter == 'N') {
    notField = true;
    for (auto it = cliArg.begin() + 1; it != cliArg.end(); ++it) {
      search.push_back(*it);
    }
  } else {
    search = cliArg;
    notField = false;
  }
}

namespace po = boost::program_options;

const std::string Query::address{"http://export.arxiv.org/api/query"};

const std::map<std::string, std::string> Query::prefixes = {
    {"title", "ti"},
    {"authors", "au"},
    {"abstract", "abs"},
};

void Query::make(CliParser &clip) {
  po::variables_map vm = clip.getCliOptions();

  for (const auto &[key, value] : prefixes) {
    if (vm.count(key)) {
      for (const auto &w : vm[key].as<std::vector<std::string>>()) {
        Field field(value, w);
        if (field.isNot()) {
          andNotField.push_back(std::move(field));
        } else {
          andField.push_back(std::move(field));
        }
      }
    }
  }

  max_results = vm["max-results"].as<int>();
  if (vm.count("ascend")) {
    sorting = "ascending";
  } else {
    sorting = "descending";
  }
};

void Query::prepare() {
  bool isFirst = true;
  std::string search_query{};
  for (auto field : andField) {
    if (isFirst) {
      isFirst = false;
      search_query += field.compose();
    } else {
      search_query += " AND " + field.compose();
    }
  }

  if (!andNotField.empty()) {
    isFirst = true;
    search_query += " ANDNOT (";
    for (auto field : andNotField) {
      if (isFirst) {
        isFirst = false;
        search_query += field.compose();
      } else {
        search_query += " OR " + field.compose();
      }
    }
    search_query += ")";
  }

  query = search_query;
};

Query::Query(CliParser &clip) {
  make(clip);
  if (andField.empty()) {
    std::cout << "Please, compose a query with at least one non-negative "
                 "field, otherwise, the query is useless."
              << std::endl;
    std::exit(1);
  }
  prepare();
};

bool Query::fetch() {
  cpr::Url url{address};
  cpr::Parameters parameters =
      cpr::Parameters{{"search_query", query},
                      {"start", "0"},
                      {"max_results", std::to_string(max_results)},
                      {"sortBy", "lastUpdatedDate"},
                      {"sortOrder", sorting}};
  cpr::Response r = cpr::Get(url, parameters);

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
