#ifndef _PARSING_H_
#define _PARSING_H_

#include <string>
#include <vector>

struct Paper {
  std::string title{};
  std::string abstract{};
  std::string url{};
  std::vector<std::string> authors{};
};

class Papers {
private:
  std::vector<Paper> papers;

public:
  Papers(std::string &response);
};

#endif
