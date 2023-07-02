/**
 * @file number_of_steps.hpp
 * @author Janus
 * @brief LeetCode problem 1342: Number of Steps to Reduce a Number to Zero
 * Given an integer num, return the number of steps to reduce it to zero.
 * In one step, if the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
 * 
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <vector>
#include <string>

namespace p1342 {

class Solution {
public:
    using ValueType = int;
    ValueType numberOfSteps(int num);
    ValueType numberOfSteps_bits(int num);
};

}

