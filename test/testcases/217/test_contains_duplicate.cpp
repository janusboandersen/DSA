/**
 * @file test_contains_duplicate.cpp
 * @author Janus
 * @brief Tests for Leetcode problem 217
 * @version 0.1
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <217/contains_duplicate.hpp>

using namespace testing;
using namespace p217;

struct TestPair {
    std::vector<int> nums;
    bool result;
};

class p217_ConstraintsAndExamples: public Test {
public:
    Solution solution;
    TestPair ex1 {{1,2,3,1}, true};
    TestPair ex2 {{1,2,3,4}, false};
    TestPair ex3 {{1,1,1,3,3,4,3,2,4,2}, true};

};

TEST_F(p217_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_EQ(solution.containsDuplicate(ex1.nums), ex1.result);
}

TEST_F(p217_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_EQ(solution.containsDuplicate(ex2.nums), ex2.result);
}

TEST_F(p217_ConstraintsAndExamples, TestCase3_MatchesExample) {
    EXPECT_EQ(solution.containsDuplicate(ex3.nums), ex3.result);
}
