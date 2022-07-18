#ifndef _CLI_HPP
#define _CLI_HPP

#include <boost/program_options/variables_map.hpp>

#include "query.hpp"

namespace po = boost::program_options;

void compose_query(int argc, char *argv[], Query &q);

#endif
