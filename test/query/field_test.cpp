#define BOOST_TEST_MODULE "FieldParserTest"
#include "field.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(constructor_no) {
  const std::string cli = "Nzola";
  Field field(cli);

  BOOST_CHECK_EQUAL(field.getField(), "zola");
  BOOST_CHECK_EQUAL(field.getBooleanOp(), "+ANDNOT+");
}

BOOST_AUTO_TEST_CASE(constructor_yes) {
  const std::string cli = "zola";
  Field field(cli);

  BOOST_CHECK_EQUAL(field.getField(), "zola");
  BOOST_CHECK_EQUAL(field.getBooleanOp(), "+AND+");
}
