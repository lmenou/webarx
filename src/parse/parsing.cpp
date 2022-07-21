#include "parsing.hpp"
#include <iostream>
#include <tinyxml2.h>

std::vector<Parseditem> parse(std::string text) {

  // This is super ugly, we can do better !
  std::vector<Parseditem> result;

  tinyxml2::XMLDocument doc;
  doc.Parse(text.c_str());

  tinyxml2::XMLHandle handle(&doc);

  tinyxml2::XMLElement *feed = handle.FirstChildElement("feed").ToElement();

  Parseditem item;
  if (feed) {
    for (tinyxml2::XMLNode *e = feed->FirstChildElement("entry"); e;
         e = e->NextSibling()) {
      tinyxml2::XMLElement *el = e->ToElement();
      if (el) {
        tinyxml2::XMLElement *summary = el->FirstChildElement("summary");
        tinyxml2::XMLElement *title = el->FirstChildElement("title");
        tinyxml2::XMLElement *url = el->FirstChildElement("id");

        if (summary)
          item.abstract = summary->GetText();

        if (title)
          item.title = title->GetText();

        if (url)
          item.url = url->GetText();

        std::vector<std::string> authors;
        for (tinyxml2::XMLNode *auth = el->FirstChildElement("author"); auth;
             auth = auth->NextSibling()) {
          tinyxml2::XMLElement *a = auth->FirstChildElement("name");
          if (a)
            authors.push_back(a->GetText());
        }
        item.authors = authors;
      }

      result.push_back(item);
    }
  }

  return result;
}
