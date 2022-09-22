enable_testing()
find_package(Boost 1.78.0 REQUIRED COMPONENTS unit_test_framework)

function(add_boost_test SOURCE_FILE_NAME DEPENDENCY_LIB)
  get_filename_component(TEST_EXECUTABLE_NAME ${SOURCE_FILE_NAME} NAME_WE)

  add_executable(${TEST_EXECUTABLE_NAME} ${SOURCE_FILE_NAME})
  foreach(DEP ${DEPENDENCY_LIB})
    target_link_libraries(${TEST_EXECUTABLE_NAME} ${DEP})
  endforeach()
  target_link_libraries(${TEST_EXECUTABLE_NAME}
                        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

  file(READ "${SOURCE_FILE_NAME}" SOURCE_FILE_CONTENTS)
  string(REGEX MATCHALL "BOOST_AUTO_TEST_CASE\\( *([A-Za-z_0-9]+) *\\)"
               FOUND_TESTS ${SOURCE_FILE_CONTENTS})

  foreach(HIT ${FOUND_TESTS})
    string(REGEX REPLACE ".*\\( *([A-Za-z_0-9]+) *\\).*" "\\1" TEST_NAME ${HIT})

    add_test(NAME "${TEST_EXECUTABLE_NAME}.${TEST_NAME}"
             COMMAND ${TEST_EXECUTABLE_NAME} --run_test=${TEST_NAME}
                     --catch_system_error=yes)
  endforeach()
endfunction()
