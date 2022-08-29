#ifndef _CLIPARSER_HPP_
#define _CLIPARSER_HPP_

#include <boost/program_options/variables_map.hpp>

namespace po = boost::program_options;

class CliParser {
private:
  po::variables_map vm{};
  bool parsed{};

public:
  CliParser(int argc, char *argv[]);
  po::variables_map getCliOptions() { return vm; }
  bool cliParsed() { return parsed; };
};
#endif