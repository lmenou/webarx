cmake_minimum_required(VERSION 3.20)

project(WebArx)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335)
FetchContent_MakeAvailable(cpr)

add_executable(webarx main.cpp)

target_compile_features(webarx PUBLIC cxx_std_11)
target_link_libraries(webarx PRIVATE cpr::cpr)
