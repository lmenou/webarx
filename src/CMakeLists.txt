add_library(query "")
target_sources(query 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/query/query.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/query/query.cpp
    )

# include(FetchContent)
# FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
#                          GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335)
# FetchContent_Declare(tinyxml2 GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
#                               GIT_TAG 1dee28e51f9175a31955b9791c74c430fe13dc82)
# FetchContent_MakeAvailable(cpr tinyxml2)

# target_link_libraries(webarx PRIVATE cpr::cpr tinyxml2::tinyxml2)
