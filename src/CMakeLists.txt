set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE query tui)

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../bin)

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

include(FetchContent)
FetchContent_Declare(
  cpr
  GIT_REPOSITORY https://github.com/libcpr/cpr.git
  GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335)
FetchContent_Declare(
  tinyxml2
  GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
  GIT_TAG 1dee28e51f9175a31955b9791c74c430fe13dc82)

FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG c033ca61ae8fb264542d0326d1309e0a3bde945a)
FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

FetchContent_MakeAvailable(cpr tinyxml2)

set(BOOST_REQUIRED_COMPONENTS program_options)
set(BOOST_MIN_VERSION 1.79.0)

find_package(Boost ${BOOST_MIN_VERSION} REQUIRED
             COMPONENTS ${BOOST_REQUIRED_COMPONENTS})
