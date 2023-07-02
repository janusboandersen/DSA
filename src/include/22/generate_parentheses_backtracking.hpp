/**
 * @file src/include/22x/generate_parentheses_backtracking.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 22: Generate parentheses (using backtracking)
 * 
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * Search tree for n=3:           
 *                               ''
 *                               / 
 *                             '('                          
 *                            /   \
 *                           /     \ 
 *                          /       \           
 *                         /         \                       
 *                        /           \
 *                       /             \
 *                      /               \
 *                     /                 \
 *                    /                   \ 
 *                   /                     \ 
 *                  /                       \      
 *               '(('                      '()'
 *               /    \                     /
 *        '((('       '(()'              '()('              
 *         \         /   \               /   \ 
 *          \   '(()('   '(())'     '()(('    '()()'          
 *           \      \       |          \         |     
 *      '((()))' '(()())' '(())()'    '()(())'   '()()()'
 * 
 * Strategy for extending potential candidates:
 * - Depth-first search
 * - Add as many left-parens as possible '('.
 * - Then, add right-parens ')' until done.
 * 
 * Recursive backtracking steps:
 * Build stage:  ((()))
 * Store result
 * Backtrack to: ((
 * Build stage:  (()())
 * Store result
 * Backtrack to: (()
 * Build stage:  (())()
 * Store result
 * Backtrack to: (
 * Build stage:  ()(())
 * Store result
 * Backtrack to: ()(
 * Build stage:  ()()()
 * Store result
 * 
 * Final result: { ((())), (()()), (())(), ()(()), ()()() }
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

namespace p22_backtracking {

class Solution {
private:
    std::vector<std::string> results;
    void extend(std::string candidate, int remaining_opens, int remaining_closes);
    
public:
    std::vector<std::string> generateParenthesis(int n);
};

} // namespace