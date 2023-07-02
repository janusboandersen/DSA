/**
 * @file src/include/20/valid_parentheses.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 20: Valid parentheses
 * 
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 *   Open brackets must be closed by the same type of brackets.
 *   Open brackets must be closed in the correct order.
 *   Every close bracket has a corresponding open bracket of the same type.
 * 
 * Approach: brackets are open and closed in a matched way, then
 *   -> A match is a set of two parens, one open-paren and one close-paren, from the same class, '()', '[]', and '{}'.
 *   -> Every matched set of parens is neautralized (no effect on other parens).
 *   -> To be valid then, 
 *      (1) for every open-paren, there must be a close-paren, and
 *      (2) for every close-paren, the previous unmatched paren must be an open-paren of the same class.
 * 
 * Can model this with a LIFO stack:
 * - Process parens left-to-right.
 * - Each open-paren is pushed onto the stack.
 * - Each close-paren pops an element off the stack.
 * - If the popped-off element does not adhere to (2), the parentheses are invalid.
 * - If there is no element to pop off, the parentheses are invalid.
 * - If the stack is not empty at the end, the parentheses are invalid.
 * 
 * Time complexity: O(n) to iterate through string, O(1) to push/pop. Overall, O(n)
 * Space complexity: Worst case O(n) for the stack.
 * 
 * @version 1.0
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>

#pragma once

namespace p20 {

class Solution {
public:
    using InputValueType = std::string;
    using ReturnValueType = bool;
    ReturnValueType isValid(InputValueType& s);
};

} // namespace