include(GetFTXUI)

add_library(${PROJECT_NAME}-tui STATIC ${CMAKE_CURRENT_SOURCE_DIR}/tui.cpp)
target_include_directories(${PROJECT_NAME}-tui
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(
  ${PROJECT_NAME}-tui
  PUBLIC ${PROJECT_NAME}-papers
  PRIVATE ftxui::screen ftxui::dom ftxui::component)
