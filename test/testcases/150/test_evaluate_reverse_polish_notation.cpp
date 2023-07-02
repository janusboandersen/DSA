/**
 * @file test/testcases/150/test_evaluate_reverse_polish_notation.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 150
 * @version 1.0
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <150/evaluate_reverse_polish_notation.hpp>

using namespace testing;
using namespace p150;

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

class p150_ConstraintsAndExamples: public Test {
public:
    Solution solution;
    TestPair ex1 { {"2","1","+","3","*"}, 9 };
    TestPair ex2 { {"4","13","5","/","+"}, 6 };
    TestPair ex3 { {"10","6","9","3","+","-11","*","/","*","17","+","5","+"}, 22 };

};

TEST_F(p150_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_EQ(solution.evalRPN(ex1.data), ex1.result);
}

TEST_F(p150_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_EQ(solution.evalRPN(ex2.data), ex2.result);
}

TEST_F(p150_ConstraintsAndExamples, TestCase3_MatchesExample) {
    EXPECT_EQ(solution.evalRPN(ex3.data), ex3.result);
}
