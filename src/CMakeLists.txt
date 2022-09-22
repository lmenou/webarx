include(FindBoostPO)
include(GetCpr)
include(GetTinyXML2)
include(GetFTXUI)

add_library(cliparse ${CMAKE_CURRENT_SOURCE_DIR}/cliparser/cliparser.cpp)

target_include_directories(
  cliparse
  PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cliparser/include>"
         "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/webarx>")
set_target_properties(
  cliparse
  PROPERTIES PUBLIC_HEADER
             ${CMAKE_CURRENT_SOURCE_DIR}/cliparser/include/cliparser.hpp)
target_compile_features(cliparse PUBLIC cxx_std_17)
target_link_libraries(cliparse Boost::program_options)

add_library(field ${CMAKE_CURRENT_SOURCE_DIR}/query/field.cpp)
target_include_directories(field
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/query/include/)
target_compile_features(field PUBLIC cxx_std_17)

add_library(query ${CMAKE_CURRENT_SOURCE_DIR}/query/query.cpp)
target_include_directories(query
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/query/include/)
target_link_libraries(query cliparse field cpr)

add_library(papers ${CMAKE_CURRENT_SOURCE_DIR}/papers/papers.cpp)
target_include_directories(papers
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/papers/include/)
target_compile_features(papers PUBLIC cxx_std_17)
target_link_libraries(papers tinyxml2)

add_library(tui ${CMAKE_CURRENT_SOURCE_DIR}/tui/tui.cpp)
target_include_directories(tui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/tui/include/)
target_link_libraries(tui papers ftxui::screen ftxui::dom ftxui::component)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} query tui)
