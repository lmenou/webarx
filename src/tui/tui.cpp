#include "tui.hpp"
#include <memory>
#include <stdlib.h>

#include "ftxui/component/captured_mouse.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"

void TUI::show(const Papers &papers) const {
  std::vector<std::string> titles = papers.getTitles();
  int selected = 0;

  auto menu_titles = ftxui::Menu(&titles, &selected);
  auto menu_titles_window = Renderer(menu_titles, [&] {
    return ftxui::window(ftxui::text("Titles"),
                         menu_titles->Render() | ftxui::vscroll_indicator |
                             ftxui::frame |
                             size(ftxui::HEIGHT, ftxui::LESS_THAN, 10));
  });

  auto summary_window = ftxui::Renderer([&] {
    return ftxui::window(ftxui::text("Abstract"),
                         ftxui::paragraph(papers[selected].summary));
  });

  auto id_window = ftxui::Renderer([&] {
    return ftxui::window(ftxui::text("Url"), ftxui::text(papers[selected].id));
  });

  auto updated_window = ftxui::Renderer([&] {
    return ftxui::window(ftxui::text("Posting Date"),
                         ftxui::text(papers[selected].updated));
  });

  auto authors_window = ftxui::Renderer([&] {
    std::string authors = [&] {
      std::string res{};
      for (auto name : papers[selected].authors) {
        res = res + name + "; ";
      }
      return res;
    }();
    return ftxui::window(ftxui::text("Authors"), ftxui::paragraph(authors));
  });

  auto info_window = ftxui::Container::Horizontal({
      id_window,
      updated_window,
      authors_window,
  });

  auto global = ftxui::Container::Vertical({
      menu_titles_window,
      summary_window,
      info_window,
  });

  auto screen = ftxui::ScreenInteractive::Fullscreen();
  screen.Loop(global);
}
