/**
 * @file test_richest_customer_wealth.cpp
 * @author Janus
 * @brief Tests for Leetcode problem 1672
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <1672/richest_customer_wealth.hpp>

using namespace testing;
using namespace p1672;

class p1672_ConstraintsAndExamples: public Test {
public:
    Solution solution;

    Solution::CustomerContainer test_vector_0   {{1,2,3},{3,2,1}};
    Solution::ValueType result_0 = 6;

    Solution::CustomerContainer test_vector_1   {{1,5},{7,3},{3,5}};
    Solution::ValueType result_1 = 10;

    Solution::CustomerContainer test_vector_2   {{2,8,7},{7,1,3},{1,9,5}};
    Solution::ValueType result_2 = 17;

};

TEST_F(p1672_ConstraintsAndExamples, TestVector0_ReturnsExampleValue) {
    EXPECT_THAT(solution.maximumWealth(test_vector_0), Eq(result_0));
}

TEST_F(p1672_ConstraintsAndExamples, TestVector1_ReturnsExampleValue) {
    EXPECT_THAT(solution.maximumWealth(test_vector_1), Eq(result_1));
}

TEST_F(p1672_ConstraintsAndExamples, TestVector2_ReturnsExampleValue) {
    EXPECT_THAT(solution.maximumWealth(test_vector_2), Eq(result_2));
}
