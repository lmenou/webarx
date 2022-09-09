include(FindBoostPO)
include(GetCpr)
include(GetTinyXML2)
include(GetFTXUI)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE query tui)

add_library(cliparse ${CMAKE_CURRENT_SOURCE_DIR}/cliparser/cliparser.cpp)
target_include_directories(cliparse
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/cliparser/)
target_compile_features(cliparse PUBLIC cxx_std_17)
target_link_libraries(cliparse PUBLIC Boost::program_options)

add_library(query ${CMAKE_CURRENT_SOURCE_DIR}/query/query.cpp)
target_include_directories(query INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/query/)
target_link_libraries(query PUBLIC cliparse cpr)

add_library(papers ${CMAKE_CURRENT_SOURCE_DIR}/papers/papers.cpp)
target_include_directories(papers INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/papers/)
target_compile_features(papers PUBLIC cxx_std_17)
target_link_libraries(papers PRIVATE tinyxml2)

add_library(tui ${CMAKE_CURRENT_SOURCE_DIR}/tui/tui.cpp)
target_include_directories(tui INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/tui/)
target_link_libraries(
  tui
  PUBLIC papers
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component)
