#define BOOST_TEST_MODULE "FieldParserTest"
#include "field.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(constructor_no) {
  const std::string cli = "Nzola";
  const std::string search = "title";
  Field field(search, cli);

  BOOST_CHECK_EQUAL(field.isNot(), true);
  BOOST_CHECK_EQUAL(field.compose(), "title:zola");
}

BOOST_AUTO_TEST_CASE(constructor_yes) {
  const std::string cli = "zola";
  const std::string search = "title";
  Field field(search, cli);

  BOOST_CHECK_EQUAL(field.isNot(), false);
  BOOST_CHECK_EQUAL(field.compose(), "title:zola");
}

