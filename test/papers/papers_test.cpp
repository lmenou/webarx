#define BOOST_TEST_MODULE "PapersTest"
#include "papers.hpp"
#include <boost/test/unit_test.hpp>
#include <fstream>
#include <string>
#include <tinyxml2.h>

BOOST_AUTO_TEST_CASE(papers_constructor) {
  std::ifstream ifs("../../../test/papers/query.xml");
  if (!ifs.is_open()) {
    std::cerr << "Could not open the file - '\n";
    exit(EXIT_FAILURE);
  }
  std::string content((std::istreambuf_iterator<char>(ifs)),
                      std::istreambuf_iterator<char>());
  Papers papers(content);

  BOOST_CHECK(papers.size() == 2);
}
