/**
 * @file richest_customer_wealth.hpp
 * @author Janus
 * @brief LeetCode problem 1672: Richest Customer Wealth
 * You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. 
 * Return the wealth that the richest customer has. 
 * A customer's wealth is the amount of money they have in all their bank accounts. 
 * The richest customer is the customer that has the maximum wealth.
 * 
 * Constraints: 
 * m == accounts.length 
 * n == accounts[i].length 
 * 1 <= m, n <= 50 
 * 1 <= accounts[i][j] <= 100
 * 
 * Max wealth value = 100*m*n = 100*50*50 = 2.5 * 10^5, which will easily fit in an int.
 * 
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <vector>

namespace p1672 {

class Solution {
public:
    using ValueType = int;
    using CustomerBalances = std::vector<ValueType>;
    using CustomerContainer = std::vector<CustomerBalances>;

    ValueType maximumWealth(CustomerContainer& accounts);
};

}

