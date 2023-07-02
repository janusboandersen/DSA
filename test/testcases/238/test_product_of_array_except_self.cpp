/**
 * @file test/testcases/238/test_product_of_array_except_self.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 238
 * @version 1.0
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <238/product_of_array_except_self.hpp>

using namespace testing;
using namespace p238;

class p238_ConstraintsAndExamples: public Test {
public:
    Solution solution;
    std::vector<int> ex1_data {1, 2, 3, 4};
    std::vector<int> ex1_result {24, 12, 8, 6};

    std::vector<int> ex2_data {-1, 1, 0, -3, 3};
    std::vector<int> ex2_result {0, 0, 9, 0, 0};
};

TEST_F(p238_ConstraintsAndExamples, TestCase1_MatchesExample) {
    auto res = solution.productExceptSelf(ex1_data); 
    EXPECT_EQ(res, ex1_result);
}

TEST_F(p238_ConstraintsAndExamples, TestCase2_MatchesExample) {
    auto res = solution.productExceptSelf(ex2_data); 
    EXPECT_EQ(res, ex2_result);
}

TEST_F(p238_ConstraintsAndExamples, TestCase1_AlternativeSoln_MatchesExample) {
    auto res = solution.productExceptSelf_alt(ex1_data); 
    EXPECT_EQ(res, ex1_result);
}

TEST_F(p238_ConstraintsAndExamples, TestCase2_AlternativeSoln_MatchesExample) {
    auto res = solution.productExceptSelf_alt(ex2_data); 
    EXPECT_EQ(res, ex2_result);
}

TEST_F(p238_ConstraintsAndExamples, TestCase1_AlternativeSoln2_MatchesExample) {
    auto res = solution.productExceptSelf_alt2(ex1_data); 
    EXPECT_EQ(res, ex1_result);
}

TEST_F(p238_ConstraintsAndExamples, TestCase2_AlternativeSoln2_MatchesExample) {
    auto res = solution.productExceptSelf_alt2(ex2_data); 
    EXPECT_EQ(res, ex2_result);
}
