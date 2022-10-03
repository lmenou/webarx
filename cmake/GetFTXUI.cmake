FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG c033ca61ae8fb264542d0326d1309e0a3bde945a)

message(
  STATUS
    "Set FTXUI_BUILD_EXAMPLES to OFF: Disable ftxui library examples building")
message(STATUS "See file cmake/GetFTXUI.cmake to set this option")
set(FTXUI_BUILD_EXAMPLES
    OFF
    CACHE BOOL "Set to ON to build examples")
FetchContent_MakeAvailable(ftxui)
