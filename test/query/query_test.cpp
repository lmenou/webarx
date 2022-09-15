#define BOOST_TEST_MODULE "FieldParserTest"
#include "cliparser.hpp"
#include "query.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(query_constructor1) {
  int argc = 5;
  char name[] = "name.cpp";
  char authors[] = "--authors";
  char author_name[] = "del_maestro";
  char title[] = "--title";
  char title_value[] = "checkerboard";
  char *argv[] = {name, authors, author_name, title, title_value};
  CliParser cli(argc, argv);
  Query q(cli);

  BOOST_CHECK_EQUAL(
      q.getQuery(),
      "http://export.arxiv.org/api/"
      "query?search_query=au:del_maestro+AND+ti:checkerboard&start=0&max_"
      "results=300&sortBy=lastUpdatedDate&sortOrder=descending");
}

BOOST_AUTO_TEST_CASE(query_constructor2) {
  int argc = 5;
  char name[] = "name.cpp";
  char authors[] = "--authors";
  char author_name[] = "del_maestro";
  char title[] = "--title";
  char title_value[] = "ncheckerboard";
  char *argv[] = {name, authors, author_name, title, title_value};
  CliParser cli(argc, argv);
  Query q(cli);

  BOOST_CHECK_EQUAL(
      q.getQuery(),
      "http://export.arxiv.org/api/"
      "query?search_query=au:del_maestro+ANDNOT+ti:checkerboard&start=0&max_"
      "results=300&sortBy=lastUpdatedDate&sortOrder=descending");
}
