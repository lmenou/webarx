#include <cpr/cpr.h>
#include <iostream>
#include <string>
#include <tinyxml2.h>

int main(int argc, char **argv) {
  cpr::Response r = cpr::Get(
      cpr::Url{"http://export.arxiv.org/api/"
               "query?search_query=all:electron&start=0&max_results=10"});
  std::cout << "Status code: " << r.status_code << '\n';

  const char *xml = r.text.c_str();
  tinyxml2::XMLDocument doc;
  doc.Parse(xml);

  tinyxml2::XMLHandle handle(&doc);

  tinyxml2::XMLElement *feed = handle.FirstChildElement("feed").ToElement();

  if (feed) {
    for (tinyxml2::XMLNode *e = feed->FirstChildElement("entry"); e;
         e = e->NextSibling()) {
      tinyxml2::XMLElement *el = e->ToElement();
      if (el) {
        tinyxml2::XMLElement *sum = el->FirstChildElement("summary");
        if (sum) {
          std::cout << sum->GetText() << std::endl;
        }
      }
    }
  }

  return 0;
}
