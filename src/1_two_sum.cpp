/**
 * @file src/1_two_sum.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 1
 * @version 1.0
 * @date 2023-06-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <1/two_sum.hpp>

namespace p1 {

using AddressContainer = std::vector<const int*>;
using Dictionary = std::unordered_map<int, AddressContainer>;

/**
 * @brief Create a collision-proof map y -> &y. Collisions for y result in chaining addresses in a vector of addresses {&y_i}.
 */
Dictionary to_dict(const std::vector<int>& nums) {
    Dictionary address_of;
    for (const auto& y : nums) { 
        address_of[y].push_back(&y);        // easy way to get from x -> y(x) -> &y
    }
    return address_of;
}

/**
 * @brief Return indices {i, j}, i != j, of a pair of numbers from nums where nums[i] + nums[j] == target.
 * Implements strategy 4: Two-pass
 */
std::vector<int> Solution::twoSum(std::vector<int>& nums, int target)
{
    auto address_of = to_dict(nums);                        // map: y -> &y. FIRST PASS.
    auto y = [target](int x){ return target - x; };         // y(x)

    auto index = [&nums](auto elem_ptr){ 
        return static_cast<int>(elem_ptr - &nums[0]);       // get i from elem_i via its pointer &elem_i.
    };

    for (const auto& x : nums) {                            // For each x,    SECOND PASS
        for (const auto& addr_y : address_of[y(x)]) {       // compute y(x). Check in map if vector holds any addresses. Traverse vector if any addresses stored, and
            if ( &x != addr_y) {                            // check if any are different than &x.
                return {index(&x), index(addr_y)};          // If so, return their indices.
            }
        }
    }

    return {0, 0};                                          // Per problem text, guaranteed to never reach here.
}

} // namespace