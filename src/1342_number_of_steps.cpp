/**
 * @file 1342_number_of_steps.cpp
 * @author Janus
 * @brief Solution to LeetCode prob. 1342
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <1342/number_of_steps.hpp>

namespace p1342 {

/**
 * @brief Returns number of steps required to reduce input num to zero.
 * 
 * @return int
 */
Solution::ValueType Solution::numberOfSteps(int num) {
    ValueType steps = 0;
    while (num > 0) {
        num = (num % 2 == 0 ? num / 2 : num - 1);   // O( log2 n )
        steps++;
    }
    return steps;
}

Solution::ValueType Solution::numberOfSteps_bits(int num) {
    ValueType steps = 0;
    while (num > 0) {
        num = ((num & 0x1) == 0x0 ? num >> 1 : num - 1);   // O( log2 n )
        steps++;
    }
    return steps;
}

} // namespace
