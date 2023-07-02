/**
 * @file test/testcases/128/test_longest_consecutive_sequence.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 128
 * @version 1.0
 * @date 2023-06-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <128/longest_consecutive_sequence.hpp>

using namespace testing;
using namespace p128;

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

class p128_ConstraintsAndExamples: public Test {
public:
    Solution solution;
    TestPair ex1 { {100,4,200,1,3,2}, 4 };
    TestPair ex2 { {0,3,7,2,5,8,4,6,0,1}, 9 };
};

TEST_F(p128_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_EQ(solution.longestConsecutive(ex1.data), ex1.result);
}

TEST_F(p128_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_EQ(solution.longestConsecutive(ex2.data), ex2.result);
}
