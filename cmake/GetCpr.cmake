find_program(GIT git REQUIRED)

if(GIT-NOTFOUND)
  message(FATAL_ERROR "\n" "Git is required to fetch the dependencies.\n"
                      "Please install the software to build webarx.\n")
endif()

include(FetchContent)

FetchContent_Declare(
  cpr
  GIT_REPOSITORY https://github.com/libcpr/cpr.git
  GIT_TAG 3baa80e66bbaba40f5aa0d9409d99d0727f80e1a)

message(STATUS "Try to find curl in the system...")
find_package(CURL COMPONENTS HTTP HTTPS)
if(CURL_FOUND)
  message(STATUS "libcurl FOUND, use the system library")
  message(STATUS "See  cmake/GetCpr.cmake to set this option")
  set(CPR_USE_SYSTEM_CURL
      ON
      CACHE
        BOOL
        "If enabled we will use the curl lib already installed on this system.")
else()
  message(STATUS "libcurl not FOUND, libcurl would be fetched")
  message(STATUS "See cmake/GetCpr.cmake to set this option")
endif()

FetchContent_MakeAvailable(cpr)
