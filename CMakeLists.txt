cmake_minimum_required(VERSION 3.20)

project(webarx
    VERSION 1.0
    DESCRIPTION "To find on arxiv"
    LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335)
FetchContent_Declare(tinyxml2 GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
                              GIT_TAG 1dee28e51f9175a31955b9791c74c430fe13dc82)
FetchContent_MakeAvailable(cpr tinyxml2)

add_executable(webarx main.cpp)

target_compile_features(webarx PUBLIC cxx_std_11)

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
    target_compile_options(webarx PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
    target_compile_options(webarx PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    target_compile_options(webarx PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_link_libraries(webarx PRIVATE cpr::cpr tinyxml2::tinyxml2)
