#include "parsing.hpp"
#include <iostream>
#include <tinyxml2.h>

void ParsedDoc::parse(std::string xmlresponse) {
  tinyxml2::XMLDocument doc;
  doc.Parse(xmlresponse.c_str());

  tinyxml2::XMLHandle handle(&doc);

  tinyxml2::XMLElement *feed = handle.FirstChildElement("feed").ToElement();

  ParsedItem item;
  if (feed) {
    for (tinyxml2::XMLNode *e = feed->FirstChildElement("entry"); e;
         e = e->NextSibling()) {
      tinyxml2::XMLElement *el = e->ToElement();
      if (el) {
        tinyxml2::XMLElement *summary = el->FirstChildElement("summary");
        tinyxml2::XMLElement *title = el->FirstChildElement("title");
        tinyxml2::XMLElement *url = el->FirstChildElement("id");

        if (summary)
          item.setAbstract(summary->GetText());

        if (title)
          item.setTitle(title->GetText());

        if (url)
          item.setUrl(url->GetText());

        std::vector<std::string> authors;
        for (tinyxml2::XMLNode *auth = el->FirstChildElement("author"); auth;
             auth = auth->NextSibling()) {
          tinyxml2::XMLElement *a = auth->FirstChildElement("name");
          if (a)
            authors.push_back(a->GetText());
        }
        item.setAuthors(authors);
      }
      parsedItems.push_back(item);
    }
  }
}

std::ostream &operator<<(std::ostream &os, const ParsedDoc &parsedDoc) {
  std::vector<ParsedItem> items = parsedDoc.getItems();
  for (auto it : items) {
    os << it.getTitle() << "\n";
    os << it.getUrl() << "\n";
    for (auto auth : it.getAuthors()) {
      os << auth << "\n";
    }
    os << "\n";
  }
  return os;
}
