/**
 * @file test_fizz_buzz.cpp
 * @author Janus
 * @brief Tests for Leetcode problem 412
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <412/fizz_buzz.hpp>

using namespace testing;
using namespace p412;

class p412_ConstraintsAndExamples: public Test {
public:
    Solution solution;

    int test_n_0 = 3;
    Solution::Container result_vector_0 {"1", "2", "Fizz"};

    int test_n_1 = 5;
    Solution::Container result_vector_1 {"1", "2", "Fizz", "4", "Buzz"};

    int test_n_2 = 15;
    Solution::Container result_vector_2 {   "1",    "2", "Fizz",    "4",     "Buzz",
                                         "Fizz",    "7",    "8", "Fizz",     "Buzz",
                                           "11", "Fizz",   "13",   "14", "FizzBuzz" };

};

TEST_F(p412_ConstraintsAndExamples, Test0_ReturnsExampleVector) {
    EXPECT_THAT(solution.fizzBuzz(test_n_0), Eq(result_vector_0));
}

TEST_F(p412_ConstraintsAndExamples, Test1_ReturnsExampleVector) {
    EXPECT_THAT(solution.fizzBuzz(test_n_1), Eq(result_vector_1));
}

TEST_F(p412_ConstraintsAndExamples, Test2_ReturnsExampleVector) {
    EXPECT_THAT(solution.fizzBuzz(test_n_2), Eq(result_vector_2));
}
