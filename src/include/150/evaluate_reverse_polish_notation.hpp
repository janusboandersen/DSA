/**
 * @file src/include/150/evaluate_reverse_polish_notation.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 150: Evaluate reverse polish notation
 * 
 * You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
 * Evaluate the expression. Return an integer that represents the value of the expression.
 * Note that:
 * - The valid operators are '+', '-', '*', and '/'.
 * Each operand may be an integer or another expression.
 * The division between two integers always truncates toward zero.
 * There will not be any division by zero.
 * The input represents a valid arithmetic expression in a reverse polish notation.
 * The answer and all the intermediate calculations can be represented in a 32-bit integer.
 * 
 * Method:
 * - RPN is a stack-based notation
 * - Evaluation is left to right
 * - Operands are pushed onto the stack
 * - Operators pop off the required number of operands, and push the result back on the stack
 * - In the specs here, all four operators are binary, so two operands must be popped off in all cases.
 * 
 * Example:
 *  2 1 + 3 *
 *  S0: 2 1   + (operands pushed until reaching operator, binary plus)
 *  S1: 3       (two operands popped off, and result of 2+1 pushed on)
 *  S2: 3 3   * (another operand pushed on until reaching operator, binary mult.)
 *  S3: 9       (result of 3*3 pushed on)
 * 
 * @version 1.0
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>

#pragma once

namespace p150 {

class Solution {
public:
    using InputValueType = std::vector<std::string>;
    using ReturnValueType = int;
    ReturnValueType evalRPN(InputValueType& tokens);
};

} // namespace