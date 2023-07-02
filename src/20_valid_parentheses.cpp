/**
 * @file src/20_valid_parentheses.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 20
 * @version 1.0
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <20/valid_parentheses.hpp>

namespace p20 {

template <typename T>
void print_vector(const std::vector<T>& v)
{
    int n = v.size()-1;
    std::cout << "v = {";
    for (const auto& elem : v) {
        std::cout << elem << (n-- ? ", " : "");
    }
    std::cout << "}" << std::endl;
}
/**
 * @brief Determines paren-correctness, and returns true for a valid structure of (nested) parens.
 * Can model this with a LIFO stack:
 * - Process parens left-to-right.
 * - Each open-paren is pushed onto the stack.
 * - Each close-paren pops an element off the stack. 
 * - If the popped-off element does not adhere to (2), the parentheses are invalid.
 * - If there is no element to pop off, the parentheses are invalid.
 * - If the stack is not empty at the end, the parentheses are invalid.
*/
Solution::ReturnValueType Solution::isValid(Solution::InputValueType& s)
{
    // Easy look-up of matching paren from same class
    std::unordered_map<char, char> matching_open_paren_for {  {')', '('}, 
                                                              {']', '['}, 
                                                              {'}', '{'}};

    std::unordered_set<char> open_parens {'(', '[', '{'};
    auto is_open_paren = [&open_parens](const char& paren_type){ return (open_parens.count(paren_type) > 0); };

    std::unordered_set<char> close_parens {')', ']', '}'};
    auto is_close_paren = [&close_parens](const char& paren_type){ return (close_parens.count(paren_type) > 0); };

    std::stack<char> unmatched_parens;

    // Process parens left-to-right.
    for (const char& p :  s) {
        if (is_open_paren(p))
        {
            // Each open-paren is pushed onto the stack
            unmatched_parens.push(p);
        }
        else if (is_close_paren(p))
        {
            // If there is no element to pop off, the parentheses are invalid.
            if (unmatched_parens.size() == 0) return false;

            // For every close-paren, the previous unmatched paren must be an open-paren of the same class. 
            // If the to-be-popped-off element does not adhere to this, the parentheses are invalid.
            if (unmatched_parens.top() != matching_open_paren_for[p]) return false;
            
            // Each close-paren pops a matching element off the top of the stack.
            // Matched pair, pop and discard.
            unmatched_parens.pop();
        }
    }

    // If the stack is not empty at the end, the parentheses are invalid.
    return (unmatched_parens.size() == 0);
}

} // namespace