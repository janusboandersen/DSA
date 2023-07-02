/**
 * @file test/testcases/739/test_daily_temperatures.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 739
 * @version 1.0
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <739/daily_temperatures.hpp>

using namespace testing;
using namespace p739;

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

class p739_ConstraintsAndExamples: public Test {
public:
    Solution solution;

    Solution::InputValueType ex1_data {73,74,75,71,69,72,76,73};
    Solution::ReturnValueType ex1_result {1,1,4,2,1,1,0,0};

    Solution::InputValueType ex2_data {30,40,50,60};
    Solution::ReturnValueType ex2_result {1,1,1,0};

    Solution::InputValueType ex3_data {30,60,90};
    Solution::ReturnValueType ex3_result {1,1,0};
};

TEST_F(p739_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_EQ(solution.dailyTemperatures(ex1_data), ex1_result);
}

TEST_F(p739_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_EQ(solution.dailyTemperatures(ex2_data), ex2_result);
}

TEST_F(p739_ConstraintsAndExamples, TestCase3_MatchesExample) {
    EXPECT_EQ(solution.dailyTemperatures(ex3_data), ex3_result);
}