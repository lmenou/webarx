#ifndef _PARSING_H_
#define _PARSING_H_

#include <iostream>
#include <string>
#include <vector>

struct Paper {
  std::string title;
  std::string abstract;
  std::string url;
  std::string date;
  std::vector<std::string> authors;
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
