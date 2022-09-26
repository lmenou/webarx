cmake_minimum_required(VERSION 3.20)

project(
  webarx
  VERSION 1.0
  DESCRIPTION "Grab on Arxiv (from the terminal?)"
  LANGUAGES CXX)

option(BUILD_WEBARX_TEST OFF "Build tests of the webarx project")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall -Wextra -Wpedantic)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(NoInSourceBuild)

add_subdirectory(src bin)

if(${BUILD_WEBARX_TEST})
  add_subdirectory(test)
endif()

include(Install)
