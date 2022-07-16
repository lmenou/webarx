cmake_minimum_required(VERSION 3.20)

project(webarx
    VERSION 1.0
    DESCRIPTION "Grab on Arxiv (from the terminal?)"
    LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

# Define the following linked targets
# - query
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE query)
