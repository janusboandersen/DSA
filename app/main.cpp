/**
 * @file main.cpp
 * @author Janus Bo Andersen
 * @brief App for Data Structures and Algorithms (DSA). All tests are in test/testcases/<problem_number>
 * @version 1.0
 * @date Q2 2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <fmt/format.h>
#include <fmt/ranges.h>
#include <config.hpp>

int main(void) {
    fmt::print("{}: {} ({})\n", project_name, project_version, project_build_type);
    for (int i = 0; i < 10; ++i) {
        std::cout << i << std::endl;
    }
    return 0;
}
