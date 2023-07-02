/**
 * @file src/include/128/longest_consecutive_sequence.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 128: Longest consecutive sequence
 * 
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * You must write an algorithm that runs in O(n) time.
 * 
 * Method overview:
 * 1) Could sort array first, then iterate through it, but then average time complexity is O(n lg n).
 * 2) Use set to quickly determine/lookup if a value exists in the array. 
 *    O(n) to build a set. 
 *    O(n) to then search through array, looking for sequences:
 *    A sequence has a start element (with no left neighbor).
 *    A sequence has a length from start element of 1 + length(rest of sequence after the start element).
 *  The max length is the max of lengths as observed when iterating across the input vector.
 * 
 * @version 1.0
 * @date 2023-06-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>

#pragma once

namespace p128 {

class Solution {
public:
    using InputValueType = std::vector<int>;
    using ReturnValueType = int;
    ReturnValueType longestConsecutive(InputValueType& nums);
};

} // namespace