/**
 * @file test/testcases/347/test_top_k_frequent_elements.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 347
 * @version 1.0
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <347/top_k_frequent_elements.hpp>

using namespace testing;
using namespace p347;

struct TestCaseData {
    int k;
    std::vector<int> data;
    std::vector<int> result;
};

class p347_ConstraintsAndExamples: public Test {
public:
    Solution solution;
};

TEST_F(p347_ConstraintsAndExamples, TestCase1_MatchesExample) {
    TestCaseData ex {
        .k = 2, 
        .data {1,1,1,2,2,3}, 
        .result {1,2}
    };
    EXPECT_THAT(solution.topKFrequent(ex.data, ex.k), UnorderedElementsAre(ex.result[0], ex.result[1]));
    EXPECT_THAT(solution.topKFrequent(ex.data, ex.k), WhenSorted(ElementsAre(1, 2)));
}

TEST_F(p347_ConstraintsAndExamples, TestCase2_MatchesExample) {
    TestCaseData ex {
        .k = 1, 
        .data {1}, 
        .result {1}
    };
    EXPECT_EQ(solution.topKFrequent(ex.data, ex.k), ex.result);
}
