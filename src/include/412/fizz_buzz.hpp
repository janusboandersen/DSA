/**
 * @file fizz_buzz.hpp
 * @author Janus
 * @brief LeetCode problem 412: Fizz Buzz
 * Given an integer n, return a string array answer (1-indexed) where:
 *
 * answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 * answer[i] == "Fizz" if i is divisible by 3.
 * answer[i] == "Buzz" if i is divisible by 5.
 * answer[i] == i (as a string) if none of the above conditions are true.
 * 
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <vector>
#include <string>

namespace p412 {

class Solution {
public:
    using ValueType = std::string;
    using Container = std::vector<ValueType>;

    Container fizzBuzz(int n);
};

}

