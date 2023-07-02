/**
 * @file src/include/238/product_of_array_except_self.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 238: Product of array except self
 * 
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i]. 
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer. 
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 * 
 * @version 1.0
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>

#pragma once

namespace p238 {

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums);
    std::vector<int> productExceptSelf_alt(std::vector<int>& nums);
    std::vector<int> productExceptSelf_alt2(std::vector<int>& nums);
};

} // namespace