#include "papers.hpp"
#include "tinyxml2.h"
#include <iostream>

Papers::Papers(std::string &response) {
  tinyxml2::XMLDocument doc;
  doc.Parse(response.c_str());

  tinyxml2::XMLHandle handle(&doc);

  tinyxml2::XMLElement *feed = handle.FirstChildElement("feed").ToElement();

  Paper paper;
  if (feed) {
    for (tinyxml2::XMLNode *e = feed->FirstChildElement("entry"); e;
         e = e->NextSibling()) {
      tinyxml2::XMLElement *el = e->ToElement();
      if (el) {
        tinyxml2::XMLElement *summary = el->FirstChildElement("summary");
        tinyxml2::XMLElement *title = el->FirstChildElement("title");
        tinyxml2::XMLElement *url = el->FirstChildElement("id");
        tinyxml2::XMLElement *date = el->FirstChildElement("updated");

        if (summary && title && url) {
          paper.abstract = summary->GetText();
          paper.title = title->GetText();
          paper.url = url->GetText();
          paper.date = date->GetText();
        }

        std::vector<std::string> authors{};
        for (tinyxml2::XMLNode *auth = el->FirstChildElement("author"); auth;
             auth = auth->NextSibling()) {
          tinyxml2::XMLElement *a = auth->FirstChildElement("name");
          if (a)
            authors.push_back(a->GetText());
        }
        paper.authors = authors;
      }
      _papers.push_back(std::move(paper));
    }
  }

  _papers_count = _papers.size();
}

std::vector<std::string> Papers::getTitles() const {
  std::vector<std::string> titles{};

  for (auto paper : _papers) {
    titles.push_back(paper.title);
  }

  return titles;
}
