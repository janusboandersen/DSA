/**
 * @file test_running_sum.cpp
 * @author Janus
 * @brief Tests for Leetcode problem 1480
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <1480/running_sum.hpp>

using namespace testing;
using namespace p1480;

class p1480_ConstraintsAndExamples: public Test {
public:
    Solution solution;

    Solution::Container test_vector_0   {1, 2, 3, 4};
    Solution::Container result_vector_0 {1, 3, 6, 10};

    Solution::Container test_vector_1   {1, 1, 1, 1, 1};
    Solution::Container result_vector_1 {1, 2, 3, 4, 5};

    Solution::Container test_vector_2   {3, 1, 2, 10, 1};
    Solution::Container result_vector_2 {3, 4, 6, 16, 17};

};

TEST_F(p1480_ConstraintsAndExamples, TestVector0_ReturnsExampleValue) {
    EXPECT_THAT(solution.runningSum(test_vector_0), Eq(result_vector_0));
}

TEST_F(p1480_ConstraintsAndExamples, TestVector1_ReturnsExampleValue) {
    EXPECT_THAT(solution.runningSum(test_vector_1), Eq(result_vector_1));
}

TEST_F(p1480_ConstraintsAndExamples, TestVector2_ReturnsExampleValue) {
    EXPECT_THAT(solution.runningSum(test_vector_2), Eq(result_vector_2));
}