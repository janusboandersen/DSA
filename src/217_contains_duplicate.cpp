/**
 * @file 217_contains_duplicate.cpp
 * @author Janus
 * @brief Solution to LeetCode prob. 217
 * @version 0.1
 * @date 2023-06-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <unordered_map>
#include <217/contains_duplicate.hpp>

namespace p217 {

using Dictionary = std::unordered_map<int, int>;

/**
 * @brief Returns true if the sequence contains a duplicate. Otherwise, false.
 * 
 */
Solution::ReturnValueType Solution::containsDuplicate(Solution::InputValueType nums)
{
    Dictionary count;
    for (auto num : nums) {
        //count[num] += 1;                      // Register that we've seen this num (init at zero)
        //if (count[num] > 1) return true;      // we've seen this num more than once before -> it's a duplicate!
        if ((count[num] += 1) > 1) return true; // Captures the above two statements into a single.
    }
    return false;                           // since we're here: no duplicates seen.
}

} // namespace
