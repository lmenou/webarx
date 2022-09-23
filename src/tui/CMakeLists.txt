include(GetFTXUI)

add_library(tui ${CMAKE_CURRENT_SOURCE_DIR}/tui.cpp)
target_include_directories(tui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(tui papers ftxui::screen ftxui::dom ftxui::component)
