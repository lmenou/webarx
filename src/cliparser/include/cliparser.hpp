#ifndef _CLIPARSER_HPP_
#define _CLIPARSER_HPP_

#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

namespace po = boost::program_options;

class CliParser {
private:
  po::options_description desc;
  po::variables_map vm{};
  bool parsed{};

public:
  CliParser(int argc, char *argv[]);
  po::variables_map getCliOptions() { return vm; }
  po::options_description getDesc() { return desc; }
  bool cliParsed() { return parsed; };
};
#endif
