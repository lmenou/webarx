include(GetTinyXML2)

add_library(papers ${CMAKE_CURRENT_SOURCE_DIR}/papers.cpp)
target_include_directories(papers
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_compile_features(papers PUBLIC cxx_std_17)
target_link_libraries(papers tinyxml2)

