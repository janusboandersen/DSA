/**
 * @file test_ransom_note.cpp
 * @author Janus
 * @brief Tests for Leetcode problem 383
 * @version 0.1
 * @date 2023-06-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <383/ransom_note.hpp>

using namespace testing;
using namespace p383;

struct TestExample {
    std::string ransomNote;
    std::string magazine;
    bool exp;
};

class p383_ConstraintsAndExamples: public Test {
public:
    Solution solution;

    TestExample case_1 {"a", "b", false};
    TestExample case_2 {"aa", "ab", false};
    TestExample case_3 {"aa", "aab", true};

};

TEST_F(p383_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_EQ(solution.canConstruct(case_1.ransomNote, case_1.magazine), case_1.exp);
}

TEST_F(p383_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_EQ(solution.canConstruct(case_2.ransomNote, case_2.magazine), case_2.exp);
}

TEST_F(p383_ConstraintsAndExamples, TestCase3_MatchesExample) {
    EXPECT_EQ(solution.canConstruct(case_3.ransomNote, case_3.magazine), case_3.exp);
}
