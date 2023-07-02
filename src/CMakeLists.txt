# List source files for our library
set(LIB_SOURCES
    algo_quick_select.cpp
    1_two_sum.cpp
    20_valid_parentheses.cpp
    22_generate_parentheses.cpp
    22_generate_parentheses_backtracking.cpp
    36_valid_sudoku.cpp
    49_group_anagrams.cpp
    128_longest_consecutive_sequence.cpp
    150_evaluate_reverse_polish_notation.cpp
    155_min_stack.cpp
    217_contains_duplicate.cpp
    238_product_of_array_except_self.cpp
    242_valid_anagram.cpp
    271_encode_and_decode_strings.cpp
    347_top_k_frequent_elements.cpp
    383_ransom_note.cpp
    412_fizz_buzz.cpp
    739_daily_temperatures.cpp
    853_car_fleet.cpp
    876_middle_of_the_linked_list.cpp
    1342_number_of_steps.cpp
    1480_running_sum.cpp
    1672_richest_customer_wealth.cpp
)

# List header files, if needed for pre-compiling
set(LIB_HEADERS
    include/algo/quick_select.hpp
    include/1/two_sum.hpp
    include/20/valid_parentheses.hpp
    include/22/generate_parentheses.hpp
    include/22/generate_parentheses_backtracking.hpp
    include/36/valid_sudoku.hpp
    include/49/group_anagrams.hpp
    include/128/longest_consecutive_sequence.hpp
    include/150/evaluate_reverse_polish_notation.hpp
    include/155/min_stack.hpp
    include/217/contains_duplicate.hpp
    include/238/product_of_array_except_self.hpp
    include/242/valid_anagram.hpp
    include/271/encode_and_decode_strings.hpp
    include/347/top_k_frequent_elements.hpp
    include/383/ransom_note.hpp
    include/412/fizz_buzz.hpp
    include/739/daily_temperatures.hpp
    include/853/car_fleet.hpp
    include/876/middle_of_the_linked_list.hpp
    include/1342/number_of_steps.hpp
    include/1480/running_sum.hpp
    include/1672/richest_customer_wealth.hpp
)

# Include paths from our library
set(LIB_INCLUDES 
    "./include/")


# Third-party dependencies in our library
# Find these if using an external package manager
if(USE_EXTERNAL_PACKAGE_MANAGER)
    # Config-mode search for the packages. The <package>-config.cmake files are in build/conan_deps/
    message(STATUS "Finding packages for ${LIBRARY_NAME}.")
    #find_package(nlohmann_json REQUIRED)
    find_package(fmt REQUIRED)
endif()

set(LIB_DEPENDENCIES
    #nlohmann_json::nlohmann_json
    fmt::fmt)

# Create compiled, statically-linked library (.a) from the sources. Variable defined in parent CMakeLists.txt.
add_library(${LIBRARY_NAME} STATIC ${LIB_SOURCES} ${LIB_HEADERS})

# Propagate our library's include path(s) for the precompiler to locate header files used in #include <...> clauses in other compilation units.
# Any target that links this library also needs its include directory.
target_include_directories(${LIBRARY_NAME} PUBLIC ${LIB_INCLUDES})

# Link the dependencies for our library
# PUBLIC/PRIVATE/INTERFACE linking affects downstream users of our library (e.g. other libraries):
#   PRIVATE:    OUR <- DEP.     Later: OTHER <- OUR.            OTHER can't use API of DEP. DEP gets private API. Need to link OTHER <- DEP.
#   PUBLIC:     OUR <- DEP.     Later: OTHER <- OUR (<- DEP).   OTHER can now use API of DEP. DEP gets public API. No need to link again.
#   INTERFACE:  Header-only libraries.
target_link_libraries(${LIBRARY_NAME} PUBLIC ${LIB_DEPENDENCIES})

# Report warnings and use warnings as errors during compilation.
if(${ENABLE_WARNINGS})
    target_set_warnings(
        ${LIBRARY_NAME}
        ${ENABLE_WARNINGS}
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

# Potentially enable LTO
target_enable_lto(${LIBRARY_NAME} ${ENABLE_LTO})

# Potentially enable linting
if(ENABLE_CLANG_TIDY)
    add_clang_tidy_to_target(${LIBRARY_NAME})
endif()
