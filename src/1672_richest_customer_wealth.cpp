/**
 * @file 1672_richest_customer_wealth.cpp
 * @author Janus
 * @brief Solution to LeetCode prob. 1672
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <numeric>
#include <1672/richest_customer_wealth.hpp>

namespace p1672 {

template <typename T> 
T max_of(T a, T b) {
    return (a >= b ? a : b);
}

/**
 * @brief Returns wealth of the richest customer
 * 
 * @return int
 */
Solution::ValueType Solution::maximumWealth(Solution::CustomerContainer& accounts) {
    ValueType maxWealth {0};
    for (const auto& customerBalances : accounts) {
        maxWealth = max_of(maxWealth, std::accumulate(customerBalances.begin(), customerBalances.end(), 0));
    }
    return maxWealth;
}

}
