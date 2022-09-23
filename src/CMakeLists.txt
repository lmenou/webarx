add_subdirectory(cliparser)
add_subdirectory(query)
add_subdirectory(papers)
add_subdirectory(tui)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} query tui)
