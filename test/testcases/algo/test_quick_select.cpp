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
#include <algo/quick_select.hpp>

using namespace testing;
using namespace algo::qs;

void print_vector(const std::vector<int>& v) {
    int n = v.size()-1;
    std::cout << "v = {";
    for (const auto& e : v) {
        std::cout << e << (n-- ? ", " : "");
    }
    std::cout << "}" << std::endl;
}

class algo_quick_select_ConstraintsAndExamples: public Test {
public:
    std::vector<int> data {17, 25, -45, 35, 51, -18, 33, 41, 19, 10, 40, 25, 44, 55, 25};
    int N = 9; // 10th smallest element, starting from 0th, 1st, 2nd, ..., 9th.
};

TEST_F(algo_quick_select_ConstraintsAndExamples, TenthSmallestElementIsThirtyFive_ElementMatchesSortedOrder) {
    std::vector<int> sorted_data = data;
    std::sort(sorted_data.begin(), sorted_data.end());

    quick_select(data.begin(), data.begin()+N, data.end());

    //print_vector(sorted_data);
    //print_vector(data);

    EXPECT_EQ(
        *(data.begin()+N), 
        *(sorted_data.begin()+N)
    );
}
