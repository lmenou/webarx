include(GetCpr)

add_library(${PROJECT_NAME}-query STATIC ${CMAKE_CURRENT_SOURCE_DIR}/query.cpp)
target_include_directories(${PROJECT_NAME}-query PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(${PROJECT_NAME}-query PUBLIC cxx_std_17)
target_link_libraries(
  ${PROJECT_NAME}-query
  PUBLIC ${PROJECT_NAME}-cliparse
  PRIVATE cpr::cpr)
