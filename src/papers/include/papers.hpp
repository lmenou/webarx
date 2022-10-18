#ifndef _PARSING_H_
#define _PARSING_H_

#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <vector>

struct Paper {
  std::string title;
  std::string summary;
  std::string id;
  std::string updated;
  std::vector<std::string> authors;

  Paper(tinyxml2::XMLElement *el);
};

class Papers {
private:
  std::vector<Paper> _papers;
  int _papers_count;

public:
  Papers(std::string &response);
  std::vector<std::string> getTitles() const;
  int size() const { return _papers_count; }
  bool empty() const {
    if (_papers_count == 0) {
      return true;
    } else {
      return false;
    }
  }
  const Paper &operator[](int i) const {
    if (i > _papers_count) {
      std::cerr
          << "Index of paper out of bounds, report the error to the developer."
          << "\n";
      std::exit(1);
    }

    return _papers[i];
  }
};

#endif
