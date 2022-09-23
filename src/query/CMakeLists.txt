include(GetCpr)

add_library(field ${CMAKE_CURRENT_SOURCE_DIR}/field.cpp)
target_include_directories(field
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_compile_features(field PUBLIC cxx_std_17)

add_library(query ${CMAKE_CURRENT_SOURCE_DIR}/query.cpp)
target_include_directories(query
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_link_libraries(query cliparse field cpr)
