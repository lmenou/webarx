#include "parsing.hpp"
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <tinyxml2.h>
#include <vector>

#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

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

std::vector<std::string> ParsedDoc::getTitles() const {
  std::vector<std::string> titles{};
  for (auto item : parsedItems) {
    titles.push_back(item.getTitle());
  }
  return titles;
}

void ParsedDoc::screenRenderer() const {
  std::vector<std::string> titles = this->getTitles();
  int selected = 0;

  auto menu_title = ftxui::Menu(&titles, &selected);
  auto renderer = Renderer(menu_title, [&] {
    return ftxui::window(ftxui::text("Titles"),
                         menu_title->Render() | ftxui::vscroll_indicator |
                             ftxui::frame |
                             size(ftxui::HEIGHT, ftxui::LESS_THAN, 10));
  });

  auto screen = ftxui::ScreenInteractive::TerminalOutput();
  screen.Loop(renderer);
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
