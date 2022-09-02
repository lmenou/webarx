#ifndef _PARSING_H_
#define _PARSING_H_

#include <iostream>
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
  int papers_count;

public:
  Papers(std::string &response);
  std::vector<std::string> getTitles();
  int size() { return papers_count; }

  Paper &operator[](int i) {
    if (i > papers_count) {
      std::cerr
          << "Index of paper out of bounds, report the error to the developer."
          << "\n";
      std::exit(1);
    }

    return papers[i];
  }
};

#endif
