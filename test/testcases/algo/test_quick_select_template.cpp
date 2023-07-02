/**
 * @file test/testcases/algo/test_quick_select.cpp
 * @author Janus Bo Andersen
 * @brief Tests for algorithm Quick select
 * @version 1.0
 * @date 2023-06-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <algorithm>
#include <utility>
#include <algo/quick_select.hpp>

using namespace testing;
using namespace algo::qs_template;

void print_vector(const std::vector<std::pair<int, int>>& v) {
    int n = v.size()-1;
    std::cout << "v = {";
    for (const auto& [e1, e2] : v) {
        std::cout << "[" << e1 << ", " << e2 << "]" << (n-- ? ", " : "");
    }
    std::cout << "}" << std::endl;
}

class algo_quick_select_template_ConstraintsAndExamples: public Test {
public:
    std::vector<std::pair<int, int>> data {{17,1}, {25,1}, {-45,1}, {35,1}, {51,1}, {-18,1}, {33,1}, {41,1}, {19,1}, {10,1}, {40,1}, {25,1}, {44,1}, {55,1}, {25,1}};
    int N = 9; // 10th smallest element, starting from 0th, 1st, 2nd, ..., 9th.
};

TEST_F(algo_quick_select_template_ConstraintsAndExamples, TenthSmallestPairedElementIsThirtyFive_ElementMatchesSortedOrder) {
    auto sorted_data = data;
    auto sort_order = [](const std::pair<int, int>& a, const std::pair<int, int>& b) { return a.first <= b.first; };

    std::sort(sorted_data.begin(), sorted_data.end(), sort_order);
    quick_select(data.begin(), data.begin()+N, data.end(), sort_order );

    print_vector(sorted_data);
    print_vector(data);

    EXPECT_EQ(
        (data.begin()+N)->first, 
        (sorted_data.begin()+N)->first
    );
}
