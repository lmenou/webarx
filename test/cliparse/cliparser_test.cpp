#define BOOST_TEST_MODULE "CliParserTest"
#include "cliparser.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(help) {
  int argc = 1;
  char name[] = "name.cpp";
  char *argv[] = {name};
  CliParser cli(argc, argv);

  BOOST_CHECK(cli.cliParsed() == false);
}
