/**
 * @file src/include/22/generate_parentheses.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 22: Generate parentheses
 * 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * This is the first naïve implementation. See 22x for a better backtracking solution.
 * 
 * Strategy for this solution:
 * - Uses a vector as a stack-like DS for building the parenthesis sequence.
 * - Stack and open/close counts are maintained in a Path class, with methods to determine valid next steps.
 * - Every time two possible valid choices for next step exist, the current Path is forked into two Paths, one taking '(' and the other taking ')'.
 * - Control maintained via the methods:
 *   - is_new() ::= nothing in the path, must take '('.
 *   - balance() ::= open - close. iff 0: then either done or add '('.
 *   - has_only_closes_left() ::= open == n and close < open.
 *   - is_done() ::= iff open == n and balance()==0, then true.
 *   - it_time_to_fork() ::= iff balance() > 0 and open < n, then can add either '(' or ')'.
 * - Paths ::= A vector of possible valid Path objects represents the result.
 * - The Paths vector is recursively expanded.
 * 
 * Example for n=3:
 *                                 is_new
 *                                   |               
 *                                  '('                          
 *                                 /  \
 *                                /    \   fork
 *                               /      \           
 *                              /        \                       
 *                             /          \
 *                            /            \
 *                           /              \
 *                          /                \
 *                         /                  \ 
 *                        /                    \ 
 *                       /                      \      
 *                    '(('                      '()'
 *             fork   /    \                     /   balance==0
 *               '((('     '(()'              '()('              
 *                 /       /   \ fork          /  \   fork
 *                /    '(()('  '(())'     '()((' '()()'          
 * only_closes   /       /       \           /      \     
 *              /       /         \         /        \
 *       '((()))'  '(()())'     '(())()' '()(())'   '()()()'     is_done
 * 
 * 
 * @version 1.0
 * @date 2023-06-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>
#include <string>

#pragma once

namespace p22 {

class Solution {
public:
    using InputValueType = int;
    using ReturnValueType = std::vector<std::string>;
    ReturnValueType generateParenthesis(InputValueType n);
};

} // namespace