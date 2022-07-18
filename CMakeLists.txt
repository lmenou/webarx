cmake_minimum_required(VERSION 3.20)
set(CMAKE_OSX_DEPLOYMENT_TARGET "12.0" CACHE STRING "Minimum OS X deployment version")

project(webarx
    VERSION 1.0
    DESCRIPTION "Grab on Arxiv (from the terminal?)"
    LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} src/main.cpp)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_range_for)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_decltype_auto)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion)

# Define the following linked targets
# - query
add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PUBLIC  
    query 
)
