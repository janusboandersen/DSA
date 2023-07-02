/**
 * @file test_number_of_steps.cpp
 * @author Janus
 * @brief Tests for Leetcode problem 1342
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <1342/number_of_steps.hpp>

using namespace testing;
using namespace p1342;

class p1342_ConstraintsAndExamples: public Test {
public:
    Solution solution;

    int test_n_0 = 14;
    Solution::ValueType result_0 = 6;

    int test_n_1 = 8;
    Solution::ValueType result_1 = 4;

    int test_n_2 = 123;
    Solution::ValueType result_2 = 12;

};

TEST_F(p1342_ConstraintsAndExamples, Test0_ReturnsExampleValue) {
    EXPECT_THAT(solution.numberOfSteps(test_n_0), Eq(result_0));
}

TEST_F(p1342_ConstraintsAndExamples, Test1_ReturnsExampleValue) {
    EXPECT_THAT(solution.numberOfSteps(test_n_1), Eq(result_1));
}

TEST_F(p1342_ConstraintsAndExamples, Test2_ReturnsExampleValue) {
    EXPECT_THAT(solution.numberOfSteps(test_n_2), Eq(result_2));
}
