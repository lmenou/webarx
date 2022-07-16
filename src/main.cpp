// #include <cpr/cpr.h>
#include <iostream>
#include <string>
// #include <tinyxml2.h>

#include "query/query.hpp"

int main(int argc, char *argv[]) {

  Query query;
  std::cout << query.GetQuery() << "\n";

  std::string field = "Patterns";
  std::string id = "title";
  query.AddSingleOrFirstField(id, field);
  std::cout << query.GetQuery() << "\n";

  std::string author = "Zwicker";
  query.AddAndField("authors", author);
  std::cout << query.GetQuery() << "\n";

  std::cout << argc << std::endl;
  for (int i = 0; i < argc; i++) {
    std::cout << argv[i] << std::endl;
  };

  // cpr::Response r = cpr::Get(
  //     cpr::Url{"http://export.arxiv.org/api/"
  //              "query?search_query=all:electron&start=0&max_results=10"});

  // const char *xml = r.text.c_str();
  // tinyxml2::XMLDocument doc;
  // doc.Parse(xml);

  // tinyxml2::XMLHandle handle(&doc);

  // tinyxml2::XMLNode *feed = handle.FirstChildElement("feed").ToNode();

  // if (feed) {
  //   for (tinyxml2::XMLNode *e = feed->FirstChildElement("entry"); e;
  //        e = e->NextSibling()) {
  //     if (e) {
  //       tinyxml2::XMLElement *sum = e->FirstChildElement("summary");
  //       if (sum) {
  //         std::cout << sum->GetText() << std::endl;
  //       }
  //     }
  //   }
  // }

  return 0;
}
