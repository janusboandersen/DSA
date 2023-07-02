/**
 * @file test/testcases/242/test_valid_anagram.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 242
 * @version 1.0
 * @date 2023-06-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <242/valid_anagram.hpp>

using namespace testing;
using namespace p242;

class p242_ConstraintsAndExamples: public Test {
public:
    Solution solution;
};

TEST_F(p242_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_EQ(solution.isAnagram("anagram", "nagaram"), true);
}

TEST_F(p242_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_EQ(solution.isAnagram("rat", "car"), false);
}

