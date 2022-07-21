#ifndef _PARSING_H_
#define _PARSING_H_

#include <string>
#include <vector>

// Represents all the interesting elements from a Query
struct Parseditem {
  std::string title;
  std::string abstract;
  std::string url;
  std::vector<std::string> authors;
};

// Returns all the parsed elements from a query
std::vector<Parseditem> parse(std::string text);

#endif
