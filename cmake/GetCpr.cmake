find_program(GIT git REQUIRED)

if(GIT-NOTFOUND)
  message(FATAL_ERROR "\n" "Git is required to fetch the dependencies.\n"
                      "Please install the software to build webarx.\n")
endif()

include(FetchContent)

FetchContent_Declare(
  cpr
  GIT_REPOSITORY https://github.com/libcpr/cpr.git
  GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335)

FetchContent_MakeAvailable(cpr)
