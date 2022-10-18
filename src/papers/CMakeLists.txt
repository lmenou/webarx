include(GetTinyXML2)

add_library(${PROJECT_NAME}-papers STATIC
            ${CMAKE_CURRENT_SOURCE_DIR}/papers.cpp)

target_include_directories(${PROJECT_NAME}-papers
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(${PROJECT_NAME}-papers PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME}-papers PUBLIC tinyxml2::tinyxml2)
