#define BOOST_TEST_MODULE "CliParserTest"
#include "cliparser.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(empty_cli) {
  int argc = 1;
  char name[] = "name.cpp";
  char *argv[] = {name};
  CliParser cli(argc, argv);

  BOOST_CHECK(cli.cliParsed() == false);
}

BOOST_AUTO_TEST_CASE(print_the_help) {
  int argc = 2;
  char name[] = "name.cpp";
  char help[] = "--help";
  char *argv[] = {name, help};
  CliParser cli(argc, argv);

  BOOST_CHECK(cli.cliParsed() == false);
}

BOOST_AUTO_TEST_CASE(parse_success) {
  int argc = 5;
  char name[] = "name.cpp";
  char authors[] = "--authors";
  char author_name[] = "zola";
  char title[] = "--title";
  char title_value[] = "nana";
  char *argv[] = {name, authors, author_name, title, title_value};
  CliParser cli(argc, argv);

  boost::program_options::variables_map vm = cli.getCliOptions();
  BOOST_CHECK(cli.cliParsed() == true);
  BOOST_CHECK_EQUAL(vm["authors"].as<std::vector<std::string> >()[0], "zola");
  BOOST_CHECK_EQUAL(vm["title"].as<std::vector<std::string> >()[0], "nana");
}
