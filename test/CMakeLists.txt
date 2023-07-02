# This file sets up individual test cases / suite into an executable linked with Google Test

# DEPRECATED: The GoogleTest framework has its own folder, which is dropped-in from its github page 
# DEPRECATED: (i.e., no system-wide installation or dependency configuration).
# DEPRECATED: Use the following three lines if GTest is in-source (test/GoogleTest_Framework)
# DEPRECATED: add_subdirectory(GoogleTest_Framework)
# DEPRECATED: include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
# DEPRECATED: include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

# Our own test executable main() (discovers all compiled tests and runs them)
set(TEST_EXECUTABLE main_test.cpp)
set(TEST_DIR testcases)

# The test files containing unit tests/cases to be compiled (no auto file discovery!).
set(TEST_FILES 
    ${TEST_DIR}/algo/test_quick_select.cpp
    ${TEST_DIR}/algo/test_quick_select_template.cpp
    ${TEST_DIR}/1/test_two_sum.cpp
    ${TEST_DIR}/20/test_valid_parentheses.cpp
    ${TEST_DIR}/22/test_generate_parentheses.cpp
    ${TEST_DIR}/22/test_generate_parentheses_backtracking.cpp
    ${TEST_DIR}/36/test_valid_sudoku.cpp
    ${TEST_DIR}/49/test_group_anagrams.cpp
    ${TEST_DIR}/128/test_longest_consecutive_sequence.cpp
    ${TEST_DIR}/150/test_evaluate_reverse_polish_notation.cpp
    ${TEST_DIR}/155/test_min_stack.cpp
    ${TEST_DIR}/217/test_contains_duplicate.cpp
    ${TEST_DIR}/238/test_product_of_array_except_self.cpp
    ${TEST_DIR}/242/test_valid_anagram.cpp
    ${TEST_DIR}/271/test_encode_and_decode_strings.cpp
    ${TEST_DIR}/347/test_top_k_frequent_elements.cpp
    ${TEST_DIR}/383/test_ransom_note.cpp
    ${TEST_DIR}/412/test_fizz_buzz.cpp
    ${TEST_DIR}/739/test_daily_temperatures.cpp
    ${TEST_DIR}/853/test_car_fleet.cpp
    ${TEST_DIR}/876/test_middle_of_the_linked_list.cpp
    ${TEST_DIR}/1342/test_number_of_steps.cpp
    ${TEST_DIR}/1480/test_running_sum.cpp
    ${TEST_DIR}/1672/test_richest_customer_wealth.cpp
)

# Test executable: target name is SomeProjectName_test_run.
# Executable uses the main() in main_test.cpp to run all tests in TEST_FILES.
add_executable(${TESTRUNNER_NAME} ${TEST_EXECUTABLE} ${TEST_FILES})

# The Google Test dependency is managed via Conan or FetchContent.
if(USE_EXTERNAL_PACKAGE_MANAGER)
    # Config-mode search for the packages. The <package>-config.cmake files are in build/conan_deps/
    message(STATUS "Finding packages for ${TESTRUNNER_NAME}.")
    find_package(GTest REQUIRED)
endif()

# Link our unit test executable (main_test.cpp) to our library and to the Test Framework.
# We are currently using our own entry point from main_test.cpp. Otherwise, link against BOTH gtest and gtest_main.
target_link_libraries(${TESTRUNNER_NAME} PUBLIC ${LIBRARY_NAME})
#  DEPRECATED: target_link_libraries(${TESTRUNNER_NAME} PUBLIC gtest)
target_link_libraries(${TESTRUNNER_NAME} PUBLIC GTest::gtest GTest::gmock)

if(ENABLE_COVERAGE)

    message(STATUS "Coverage for ${TESTRUNNER_NAME} is ON.")

    # Define coverage scope, in particular, we only want to test the library (src/) and thus exclude all other things external to that.
    set(COVERAGE_MAIN "coverage")
    set(COVERAGE_EXCLUDES
        "${PROJECT_SOURCE_DIR}/app/*"
        "${PROJECT_SOURCE_DIR}/build/*"
        "${PROJECT_SOURCE_DIR}/cmake/*"
        "${PROJECT_SOURCE_DIR}/docs/*"
        "${PROJECT_SOURCE_DIR}/test/*"
        "${PROJECT_SOURCE_DIR}/third_party/*"
        "${PROJECT_SOURCE_DIR}/tools/*"
        "/usr/include/*"
        "/root/.conan2/*")

    # Make coverage for the testrunner only
    setup_target_for_coverage_lcov(
        NAME ${COVERAGE_MAIN}
        EXECUTABLE ${TESTRUNNER_NAME}
        DEPENDENCIES ${TESTRUNNER_NAME})

endif()
