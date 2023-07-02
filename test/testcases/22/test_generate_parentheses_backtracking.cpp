/**
 * @file test/testcases/22x/test_generate_parentheses_backtracking.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 22x
 * @version 1.0
 * @date 2023-06-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <22/generate_parentheses_backtracking.hpp>

using namespace testing;
using namespace p22_backtracking;


class p22_backtracking_ConstraintsAndExamples: public Test {
public:
    Solution solution;
};

TEST_F(p22_backtracking_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_THAT(
        solution.generateParenthesis(3), 
        UnorderedElementsAreArray({"((()))", "(()())", "(())()", "()(())", "()()()"})
    );
}

TEST_F(p22_backtracking_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_THAT(
        solution.generateParenthesis(1), 
        UnorderedElementsAreArray({"()"})
    );
}
