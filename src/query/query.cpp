#include "query.hpp"
#include <cpr/cpr.h>

bool QueryUtil::isupper(char ch) {
  return std::isupper(static_cast<unsigned char>(ch));
}

Field::Field(const std::string prefix, const std::string cliArg) {
  _field = prefix;

  char boolLetter = cliArg[0];
  if (QueryUtil::isupper(boolLetter)) {
    _fType = boolLetter;
    for (auto it = cliArg.begin() + 1; it != cliArg.end(); ++it) {
      _search.push_back(*it);
    }
  } else {
    _search = cliArg;
  }
}

namespace po = boost::program_options;

const std::string Query::address{"http://export.arxiv.org/api/query"};

const std::map<std::string, std::string> Query::_prefixes = {
    {"title", "ti"},
    {"authors", "au"},
    {"abstract", "abs"},
};

void Query::make(CliParser &clip) {
  po::variables_map vm = clip.getCliOptions();

  for (const auto &[key, value] : _prefixes) {
    if (vm.count(key)) {
      for (const auto &w : vm[key].as<std::vector<std::string>>()) {
        Field field(value, w);
        if (QueryUtil::isupper(field.fieldType())) {
          if (field.fieldType() == 'N') {
            _andNotField.push_back(std::move(field));
          } else {
            _andOrField.push_back(std::move(field));
          }
        } else {
          _andField.push_back(std::move(field));
        }
      }
    }
  }

  _max_results = vm["max-results"].as<int>();
  if (vm.count("ascend")) {
    _sorting = "ascending";
  } else {
    _sorting = "descending";
  }
};

void Query::prepare() {
  bool isFirst = true;
  std::string search_query{};
  for (auto &field : _andField) {
    if (isFirst) {
      isFirst = false;
      search_query += field.compose();
    } else {
      search_query += " AND " + field.compose();
    }
  }

  if (!_andOrField.empty()) {
    for (auto &field : _andOrField) {
      search_query += " OR " + field.compose();
    }
  }

  if (!_andNotField.empty()) {
    isFirst = true;
    search_query += " ANDNOT (";
    for (auto &field : _andNotField) {
      if (isFirst) {
        isFirst = false;
        search_query += field.compose();
      } else {
        search_query += " OR " + field.compose();
      }
    }
    search_query += ")";
  }

  _query = search_query;
};

Query::Query(CliParser &clip) {
  make(clip);
  if (_andField.empty()) {
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
      cpr::Parameters{{"search_query", _query},
                      {"start", "0"},
                      {"max_results", std::to_string(_max_results)},
                      {"sortBy", "lastUpdatedDate"},
                      {"sortOrder", _sorting}};
  cpr::Response r = cpr::Get(url, parameters);
  std::cout << r.url << "\n";
  std::exit(0);

  if (r.status_code == 0) {
    std::cerr << r.error.message << std::endl;
    return false;
  } else if (r.status_code >= 400) {
    std::cerr << "Error [" << r.status_code << "] making request" << std::endl;
    return false;
  } else {
    _response = r.text;
  }

  return true;
};
