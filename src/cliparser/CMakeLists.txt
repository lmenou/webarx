include(FindBoostPO)

add_library(${PROJECT_NAME}-cliparse STATIC
            ${CMAKE_CURRENT_SOURCE_DIR}/cliparser.cpp)
target_include_directories(${PROJECT_NAME}-cliparse
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(${PROJECT_NAME}-cliparse PUBLIC cxx_std_17)
target_link_libraries(${PROJECT_NAME}-cliparse Boost::program_options)
