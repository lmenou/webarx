#include <cpr/cpr.h>
#include <iostream>
#include <string>

int main(int argc, char **argv) {
  cpr::Response r = cpr::Get(
      cpr::Url{"http://export.arxiv.org/api/"
               "query?search_query=all:electron&start=0&max_results=10"});
  std::cout << "Status code: " << r.status_code << '\n';
  std::cout << "Header:\n";
  std::cout << "Text: " << r.text << '\n';
  return 0;
}
