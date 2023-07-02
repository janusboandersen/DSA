/**
 * @file src/include/1/two_sum.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 1: Two sum
 * 
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * You can return the answer in any order.
 * 
 * Given x and target, search for y such that x+y=target. -> y(x) ::= target - x.
 * 
 * Strategy idea 1: Brute force. O(n^2)
 *  For each x, compute y(x). Linear search rest of list for y(x). O(n*n)
 *  - Wouldn't need to search before, as that would already have returned a match.
 * 
 * Strategy idea 2: Sort-then-search. O(n lg n)
 *  Sort list O(n lg n)
 *  For each x, compute y(x). If y < x, search left side of list, if y >= x search right side of list. O(n/2)
 * 
 * Strategy idea 3: Look-up. O(2n) ~ O(n).
 *  Make hashmap<int, int*> ::= y(x) -> &y. O(n)
 *  For each x, compute y(x). Check in map if y exists, and if so, get its address. Worst case O(n).
 *  BUT this only works if x != y(x), otherwise collision.
 * 
 * Strategy idea 4 (IMPLEMENTED). Two-pass look up with collision-handling. O(2n) ~ O(n)
 *  Make hashmap<int, vector<int*>> :: y(x) -> [&y_0, ...]. O(n)
 *  For each x, compute y(x). Check in map if vector holds any addresses, if so traverse vector and check if any are different than &x. O(n).
 * 
 * Strategy idea 5 (NOT IMPLEMENTED). One-pass look-up / look-back. O(n).
 *  Build hashmap AND make look-up simultaneously.
 *  For each x, check if map[y(x)] exists.
 *   If so, return indices of x and y(x).
 *   Else, update with map[x] = &x.
 * 
 * @version 1.0
 * @date 2023-06-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>

#pragma once

namespace p1 {

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target);
};

} // namespace