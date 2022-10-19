#include "papers.hpp"
#include <iostream>

Paper::Paper(tinyxml2::XMLElement *el) {
  tinyxml2::XMLElement *title = el->FirstChildElement("title");
  tinyxml2::XMLElement *summary = el->FirstChildElement("summary");
  tinyxml2::XMLElement *id = el->FirstChildElement("id");
  tinyxml2::XMLElement *updated = el->FirstChildElement("updated");

  if (summary && title && id && updated) {
    this->title = title->GetText();
    this->summary = summary->GetText();
    this->updated = updated->GetText();
    this->id = id->GetText();
  }

  std::vector<std::string> authors;
  for (tinyxml2::XMLNode *auth = el->FirstChildElement("author"); auth;
       auth = auth->NextSibling()) {
    tinyxml2::XMLElement *a = auth->FirstChildElement("name");
    if (a)
      authors.push_back(a->GetText());
  }
  this->authors = authors;
}

Papers::Papers(std::string &response) {
  tinyxml2::XMLDocument doc;
  doc.Parse(response.c_str());

  tinyxml2::XMLHandle handle(&doc);

  tinyxml2::XMLElement *feed = handle.FirstChildElement("feed").ToElement();
  if (feed) {
    tinyxml2::XMLNode *num_item =
        feed->FirstChildElement("opensearch:itemsPerPage");
    tinyxml2::XMLElement *el_item = num_item->ToElement();
    tinyxml2::XMLNode *num_result =
        feed->FirstChildElement("opensearch:totalResults");
    tinyxml2::XMLElement *el_result = num_result->ToElement();

    if (el_item && el_result) {
      int m = std::stoi(el_item->GetText());
      int n = std::stoi(el_result->GetText());
      _papers_count = (m > n) ? n : m;
    } else {
      std::cout << "An error occured while parsing the query result, please "
                   "report the error to the developer\n";
    }

    if (_papers_count == 0) {
      std::cout
          << "Your query returned an empty result, please make a new one.\n";
      std::exit(0);
    } else {
      std::vector<Paper> papers;
      papers.reserve(_papers_count);

      for (tinyxml2::XMLNode *e = feed->FirstChildElement("entry"); e;
           e = e->NextSibling()) {
        tinyxml2::XMLElement *el = e->ToElement();
        if (el) {
          Paper paper(el);
          papers.push_back(std::move(paper));
        } else {
          std::cerr << "An error occurred while parsing the response, please "
                       "report the error to the developer\n";
        }
      }

      _papers = std::move(papers);
    }
  } else {
    std::cout << "Your query returned a wrongly formatted result, please "
                 "report the error to the developer\n";
  }
}

std::vector<std::string> Papers::getTitles() const {
  std::vector<std::string> titles(_papers_count);

  for (int i = 0; i < _papers_count; i++) {
    titles[i] = _papers[i].title;
  }
  return titles;
}
