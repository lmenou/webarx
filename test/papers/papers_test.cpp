#define BOOST_TEST_MODULE "PapersTest"
#include "cliparser.hpp"
#include "papers.hpp"
#include "query.hpp"
#include <boost/test/unit_test.hpp>
#include <fstream>
#include <string>
#include <tinyxml2.h>

BOOST_AUTO_TEST_CASE(papers_constructor) {
  std::ifstream ifs("../../../test/papers/query.xml");
  if (!ifs.is_open()) {
    std::cerr << "Could not open the file - '\n";
    std::exit(EXIT_FAILURE);
  }
  std::string content((std::istreambuf_iterator<char>(ifs)),
                      std::istreambuf_iterator<char>());
  Papers papers(content);

  BOOST_CHECK(papers.size() == 2);
}

BOOST_AUTO_TEST_CASE(papers_fetch_yes) {
  int argc = 5;
  char name[] = "name.cpp";
  char authors[] = "--authors";
  char author_name[] = "del_maestro";
  char title[] = "--title";
  char title_value[] = "checkerboard";
  char *argv[] = {name, authors, author_name, title, title_value};
  CliParser cli(argc, argv);

  Query q(cli);
  bool success = q.fetch();

  if (success) {
    std::string response = q.getResponse();
    Papers papers(response);

    BOOST_CHECK_EQUAL(papers.size(), 1);
  } else {
    std::exit(EXIT_FAILURE);
  }
}

BOOST_AUTO_TEST_CASE(papers_fetch_no) {
  int argc = 7;
  char name[] = "name.cpp";
  char authors[] = "--authors";
  char author_name[] = "del_maestro";
  char title[] = "--title";
  char title_value[] = "Ncheckerboard";
  char max_res[] = "--max-results";
  char max[] = "10";
  char *argv[] = {name, authors, author_name, title, title_value, max_res, max};
  CliParser cli(argc, argv);

  Query q(cli);
  bool success = q.fetch();

  if (success) {
    std::string response = q.getResponse();
    Papers papers(response);

    BOOST_CHECK_EQUAL(papers.size(), 10);
  } else {
    std::exit(EXIT_FAILURE);
  }
}
