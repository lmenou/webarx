add_library(query "")
target_sources(query 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/query/query.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/query/query.cpp
    )
target_compile_features(query PUBLIC 
    cxx_auto_type
    cxx_inline_namespaces
    )

add_library(parse "")
target_sources(parse 
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/parse/parsing.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/parse/parsing.cpp
    )

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG beb9e98806bb84bcc130a2cebfbcbbc6ce62b335)
FetchContent_Declare(tinyxml2 GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
                              GIT_TAG 1dee28e51f9175a31955b9791c74c430fe13dc82)
FetchContent_MakeAvailable(cpr tinyxml2)

# BOOST !
set(BOOST_REQUIRED_COMPONENTS
    program_options
)
set(BOOST_MIN_VERSION 1.79.0)
find_package(
    Boost ${BOOST_MIN_VERSION} REQUIRED
    COMPONENTS ${BOOST_REQUIRED_COMPONENTS}
)

find_package(
    Boost ${BOOST_MIN_VERSION} REQUIRED
    COMPONENTS ${BOOST_REQUIRED_COMPONENTS}
)

target_link_libraries(query PUBLIC Boost::program_options cpr::cpr)
target_link_libraries(parse PUBLIC tinyxml2::tinyxml2)
