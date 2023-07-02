/**
 * @file test/testcases/22/test_generate_parentheses.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 22
 * @version 1.0
 * @date 2023-06-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <22/generate_parentheses.hpp>

using namespace testing;
using namespace p22;

class p22_ConstraintsAndExamples: public Test {
public:
    Solution solution;
};

TEST_F(p22_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_THAT(
        solution.generateParenthesis(3), 
        UnorderedElementsAreArray({"((()))", "(()())", "(())()", "()(())", "()()()"})
    );
}

TEST_F(p22_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_THAT(
        solution.generateParenthesis(1), 
        UnorderedElementsAreArray({"()"})
    );
}
