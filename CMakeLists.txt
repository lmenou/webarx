cmake_minimum_required(VERSION 3.20)

project(
  webarx
  VERSION 1.0
  DESCRIPTION "Grab on Arxiv (from the terminal?)"
  LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "Build type not chosen, choose Release type be default")
  set(CMAKE_BUILD_TYPE
      "Release"
      CACHE STRING "Choose the type of build, options are: Debug Release
RelWithDebInfo MinSizeRel." FORCE)
endif()

option(WEBARX_BUILD_TESTS OFF "Build tests of the webarx project")
if(NOT WEBARX_BUILD_TESTS)
  message(STATUS "WEBARX_BUILD_TESTS not set: Disable tests building")
  message(STATUS "See CMakeLists.txt to set this option")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall -Wextra -Wpedantic)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(NoInSourceBuild)

add_subdirectory(src bin)

if(${WEBARX_BUILD_TESTS})
  add_subdirectory(test)
endif()

include(Install)
