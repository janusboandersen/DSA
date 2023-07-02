/**
 * @file test/testcases/20/test_valid_parentheses.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 20
 * @version 1.0
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <20/valid_parentheses.hpp>

using namespace testing;
using namespace p20;

template <typename T>
void print_vector(const std::vector<T>& v)
{
    int n = v.size()-1;
    std::cout << "v = {";
    for (const auto& elem : v) {
        std::cout << elem << (n-- ? ", " : "");
    }
    std::cout << "}" << std::endl;
}

struct TestPair {
    Solution::InputValueType data;
    Solution::ReturnValueType result;
};

class p20_ConstraintsAndExamples: public Test {
public:
    Solution solution;
    TestPair ex1 { "()", true };
    TestPair ex2 { "()[]{}", true };
    TestPair ex3 { "(]", false };

};

TEST_F(p20_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_EQ(solution.isValid(ex1.data), ex1.result);
}

TEST_F(p20_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_EQ(solution.isValid(ex2.data), ex2.result);
}

TEST_F(p20_ConstraintsAndExamples, TestCase3_MatchesExample) {
    EXPECT_EQ(solution.isValid(ex3.data), ex3.result);
}