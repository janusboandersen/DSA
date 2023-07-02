/**
 * @file src/347_top_k_frequent_elements.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 347
 * @version 1.0
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <unordered_map>
#include <utility>
#include <array>
#include <347/top_k_frequent_elements.hpp>
#include <algo/quick_select.hpp>

namespace p347 {

using Map = std::unordered_map<int, int>;
using Pair = std::pair<int, int>;

void print_vector(const std::vector<Pair>& vec)
{
    auto n {vec.size()};
    std::cout << "v = {";
    for (const auto& [e1, e2] : vec)
        std::cout << "[" << e1 << ", " << e2 << "]" << (--n ? ", " : "");
    std::cout << "};\n";
}

Solution::ReturnValueType Solution::topKFrequent(InputValueType& nums, int k)
{
    // Frequency count, O(N). {Value: Frequency}
    Map map;
    for (const auto& val: nums) {
        map[val]++;
    }

    // Transform to sortable vector, O(N)
    // Pair order is <Value, Frequency>, we want to sort the pairs by Frequency (second element)
    std::vector<Pair> frequency_pairs (map.begin(), map.end());

    // In-place partitioning of the size-M vector into M-k smallest elements, and k largest elements. ~O(lg n)
    // "Sorting" by second element in the Pair
    auto M = frequency_pairs.size();
    auto sort_order = [](const Pair& a, Pair& b) { return a.second <= b.second; };
    algo::qs_template::quick_select(
        frequency_pairs.begin(), 
        frequency_pairs.begin() + (M-k-1), 
        frequency_pairs.end(),
        sort_order
    );
    //print_vector(frequency_pairs);

    // Extract the k values that are larger than the (M-k)'th value. O(k)
    std::vector<int> k_largest;
    for (auto it = frequency_pairs.begin() + (M-k); it != frequency_pairs.end(); it++) {
        k_largest.push_back(it->first);
    }
    
    return k_largest;
}

} // namespace