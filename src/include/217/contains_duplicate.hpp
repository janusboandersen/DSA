/**
 * @file contains_duplicatet.hpp
 * @author Janus
 * @brief LeetCode problem 217: Contains Duplicate
 * 
 * Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
 * 
 * No constraints on time or space complexity.
 * 
 * Strategy 1:
 *  Copy the array -> O(n)
 *  Sort the array -> O(n lg n)
 *  Traverse linearly to check for adjacent duplicates -> O(n)
 *  
 * Strategy 2:
 *  Create hashmap from array <int:num, int:count_of_num> -> O(n)
 *  Check hashmap for duplicates (count_of_num > 1) -> O(n)
 * 
 * Strategy 3:
 *  Like #2, but check the hashmap for duplicates while building it -> worst case O(n)
 * 
 * @version 0.1
 * @date 2023-06-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <vector>

namespace p217 {

class Solution {
public:
    using ReturnValueType = bool;
    using InputValueType = std::vector<int>&;
    ReturnValueType containsDuplicate(InputValueType nums);
};

} // namespace
