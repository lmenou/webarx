FetchContent_Declare(
  tinyxml2
  GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
  GIT_TAG 1dee28e51f9175a31955b9791c74c430fe13dc82)

message(
  STATUS
    "Set tinyxml2_BUILD_TESTING to OFF: Disable tinyxml2 library tests building"
)
message(STATUS "See file cmake/GetTinyXML2.cmake to set this option")
set(tinyxml2_BUILD_TESTING
    OFF
    CACHE BOOL "Build tests for tinyxml2")
FetchContent_MakeAvailable(tinyxml2)
