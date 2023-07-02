/**
 * @file src/include/347/top_k_frequent_elements.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 347: Top k frequent elements
 * 
 * Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
 * 
 * This is a combined counting and selection problem (combinatorial):
 *  - Can use hashmap to count frequencies into M unique bins, O(N)
 *  - Can use quick-select to find Kth highest frequency, O(lg M)
 *  - Can return vector of K values, O(K).
 * 
 * Strategy idea 1: O(N + M + lg M + K) ~ O(N) 
 *   - With hashmap<value:int, frequency_count:int> get frequency count of any value in O(N) time.
 *   - With M (M <= N) unique value bins, transform back to sortable vector, O(M).
 * 
 *   - Sort by the frequency count in O(M lg M) time, and choose the K first of these.
 *   -OR-
 *   - Use QuickSelect algo, O(lg M) to partition into M-k smallest and k-largest frequencies
 * 
 *   - Copy out the needed K elements, O(K)
 *   
 * C++ has std::nth_element, but already have custom quick_select algorithm in algo/quick_select.
 *   
 * @version 1.0
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>

#pragma once

namespace p347 {

class Solution {
public:
    using InputValueType = std::vector<int>;
    using ReturnValueType = std::vector<int>;
    ReturnValueType topKFrequent(InputValueType& nums, int k);
};

} // namespace