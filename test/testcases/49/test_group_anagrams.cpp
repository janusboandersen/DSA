/**
 * @file test/testcases/49/test_group_anagrams.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 49
 * @version 1.0
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <49/group_anagrams.hpp>

using namespace testing;
using namespace p49;

class p49_ConstraintsAndExamples: public Test {
public:
    Solution solution;
    Solution::InputValueType ex1_strs { "eat","tea","tan","ate","nat","bat" };
    Solution::ReturnValueType ex1_res { {"bat"}, {"tan", "nat"}, {"eat","tea","ate"} };

    Solution::InputValueType ex2_strs { "" };
    Solution::ReturnValueType ex2_res { {""} };

    Solution::InputValueType ex3_strs { "a" };
    Solution::ReturnValueType ex3_res { {"a"} };
};

TEST_F(p49_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_THAT(solution.groupAnagrams(ex1_strs), UnorderedElementsAre(ex1_res[0], ex1_res[1], ex1_res[2]));
}

TEST_F(p49_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_THAT(solution.groupAnagrams(ex2_strs), UnorderedElementsAre(ex2_res[0]));
}

TEST_F(p49_ConstraintsAndExamples, TestCase3_MatchesExample) {
    EXPECT_THAT(solution.groupAnagrams(ex3_strs), UnorderedElementsAre(ex3_res[0]));
}

