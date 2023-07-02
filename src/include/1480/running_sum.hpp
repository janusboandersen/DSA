/**
 * @file running_sum.hpp
 * @author Janus
 * @brief LeetCode problem 1480: Running sum of 1D array
 * Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]). Return the running sum of nums.
 * 
 * Constraints:
 * 1 <= nums.length <= 1000
 * -10^6 <= nums[i] <= 10^6
 * 
 * So, largest sum would be 10^3 * 10^6 = 10^9 ~ 2^30. (log2(x^n) = log10(x^n)/log10(2) = n / log10(2) ~ 3.33 * n.)
 * So, result will fit inside 32-bit signed int.
 * 
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <vector>

namespace p1480 {

class Solution {
public:
    using ValueType = int;
    using Container = std::vector<ValueType>;
    Container runningSum(Container& nums);
};

}

