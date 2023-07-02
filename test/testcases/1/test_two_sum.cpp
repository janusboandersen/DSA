/**
 * @file test/testcases/1/test_two_sum.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 1
 * @version 1.0
 * @date 2023-06-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <1/two_sum.hpp>

using namespace testing;
using namespace p1;

class p1_ConstraintsAndExamples: public Test {
public:
    Solution solution;

    // Example 1
    std::vector<int> ex1_nums {2,7,11,15};
    int ex1_target = 9;
    std::vector<int> ex1_result {0, 1};

    // Example 2
    std::vector<int> ex2_nums {3,2,4};
    int ex2_target = 6;
    std::vector<int> ex2_result {1, 2};

    // Example 3
    std::vector<int> ex3_nums {3,3};
    int ex3_target = 6;
    std::vector<int> ex3_result {0, 1};
};

TEST_F(p1_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_EQ(solution.twoSum(ex1_nums, ex1_target), ex1_result);
}

TEST_F(p1_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_EQ(solution.twoSum(ex2_nums, ex2_target), ex2_result);
}

TEST_F(p1_ConstraintsAndExamples, TestCase3_MatchesExample) {
    EXPECT_EQ(solution.twoSum(ex3_nums, ex3_target), ex3_result);
}
