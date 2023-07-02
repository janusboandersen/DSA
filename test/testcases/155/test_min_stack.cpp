/**
 * @file test/testcases/155/test_min_stack.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 155
 * @version 1.0
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <155/min_stack.hpp>

using namespace testing;
using namespace p155;

TEST(p155_ConstraintsAndExamples, TestCase1_MatchesExample) {
    MinStack* min_stack = new MinStack;
    min_stack->push(-2);
    min_stack->push(0);
    min_stack->push(-3);
    EXPECT_EQ(min_stack->getMin(), -3);
    min_stack->pop();
    EXPECT_EQ(min_stack->top(), 0);
    EXPECT_EQ(min_stack->getMin(), -2);
    delete min_stack;
}
