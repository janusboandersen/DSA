/**
 * @file src/22x_generate_parentheses_backtracking.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 22 using recursive backtracking.
 * @version 1.0
 * @date 2023-06-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <22/generate_parentheses_backtracking.hpp>

namespace p22_backtracking {

inline bool is_done(int remaining_opens, int remaining_closes)
{
    return (remaining_opens == 0 && remaining_closes == 0);
}

inline bool can_go_left(int remaining_opens)
{
    return (remaining_opens > 0);
}

inline bool can_go_right(int remaining_opens, int remaining_closes)
{
    return (remaining_closes > remaining_opens);
}

inline std::string go_left_from(std::string candidate)
{
    return candidate + '(';
}

inline std::string go_right_from(std::string candidate)
{
    return candidate + ')';
}

void inform(std::string action, std::string candidate, int remaining_opens, int remaining_closes)
{
    std::cout << action << ": " << "'" << candidate << "'" << " [rem_opens=" << remaining_opens << ", rem_closes=" << remaining_closes << "]" <<std::endl;
}

/**
 * @brief Recursive backtracking solution to find all possible valid pairs of parentheses.
 */
void Solution::extend(std::string candidate, int remaining_opens, int remaining_closes)
{
    // Accept: Candidate is a final solution. Store and backtrack.
    if (is_done(remaining_opens, remaining_closes)) {
        //inform("Solution", candidate, remaining_opens, remaining_closes);
        results.push_back(candidate);
        return;
    }

    // First extension: Go left in search tree, and recursively extend search tree from there
    if (can_go_left(remaining_opens)) {
        //inform("Go left from", candidate, remaining_opens, remaining_closes);
        extend(go_left_from(candidate), remaining_opens - 1, remaining_closes);
    }
        
    // Next extension: Go right in search tree, and recursively extend search tree from there
    if (can_go_right(remaining_opens, remaining_closes)) {
        //inform("Go right from", candidate, remaining_opens, remaining_closes);
        extend(go_right_from(candidate), remaining_opens, remaining_closes - 1);
    }

    // Backtrack along call stack
    //inform("Backtracking from", candidate, remaining_opens, remaining_closes);
    return;
}

std::vector<std::string> Solution::generateParenthesis(int n)
{
    std::string seed_candidate = "";
    extend(seed_candidate, n, n);
    return results;
}

} // namespace