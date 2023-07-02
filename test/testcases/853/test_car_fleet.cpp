/**
 * @file test/testcases/853/test_car_fleet.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 853
 * @version 1.0
 * @date 2023-07-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <853/car_fleet.hpp>

using namespace testing;
using namespace p853;

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

class p853_ConstraintsAndExamples: public Test {
public:
    Solution solution;

    // Example 1
    int ex1_target = 12;
    std::vector<int> ex1_pos {10,8,0,5,3};
    std::vector<int> ex1_speed {2,4,1,1,3};
    int ex1_res = 3;

    // Example 2
    int ex2_target = 10;
    std::vector<int> ex2_pos {3};
    std::vector<int> ex2_speed {3};
    int ex2_res = 1;

    // Example 3
    int ex3_target = 100;
    std::vector<int> ex3_pos {0,2,4};
    std::vector<int> ex3_speed {4,2,1};
    int ex3_res = 1;
};

TEST_F(p853_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_EQ(solution.carFleet(ex1_target, ex1_pos, ex1_speed), ex1_res);
}

TEST_F(p853_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_EQ(solution.carFleet(ex2_target, ex2_pos, ex2_speed), ex2_res);
}

TEST_F(p853_ConstraintsAndExamples, TestCase3_MatchesExample) {
    EXPECT_EQ(solution.carFleet(ex3_target, ex3_pos, ex3_speed), ex3_res);
}