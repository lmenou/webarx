include(FindBoostPO)

add_library(cliparse ${CMAKE_CURRENT_SOURCE_DIR}/cliparser.cpp)
target_include_directories(
  cliparse PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                  "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/webarx>")
set_target_properties(
  cliparse PROPERTIES PUBLIC_HEADER
                      ${CMAKE_CURRENT_SOURCE_DIR}/include/cliparser.hpp)
target_compile_features(cliparse PUBLIC cxx_std_17)
target_link_libraries(cliparse Boost::program_options)
