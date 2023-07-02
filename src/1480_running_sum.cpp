/**
 * @file 1480_running_sum.cpp
 * @author Janus
 * @brief Solution to LeetCode prob. 1480
 * @version 0.1
 * @date 2023-06-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <fmt/format.h>
#include <1480/running_sum.hpp>

namespace p1480 {

/**
 * @brief Accumulates
 * 
 * @return std::vector<int>
 */
Solution::Container Solution::runningSum(Solution::Container& nums) {
    Solution::ValueType accumulate {0};
    Solution::Container running_sum;

    for (const auto& x : nums) {
        accumulate += x;
        running_sum.push_back(accumulate);
    }
    return running_sum;
}

}
