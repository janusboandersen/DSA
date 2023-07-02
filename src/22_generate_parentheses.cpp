/**
 * @file src/22_generate_parentheses.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 22
 * @version 1.0
 * @date 2023-06-27
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <22/generate_parentheses.hpp>

namespace p22 {

class Path {
public:
    Path(int depth) : max_opens{depth}, n_opens{0}, n_closes{0} {};
    std::size_t size() const { return stack.size(); }
    int remaining_opens() const { return (max_opens - n_opens); }
    int remaining_closes() const { return (max_opens - n_closes); }
    int open_balance() const { return (n_opens - n_closes); }
    bool is_new() const { return (stack.size() == 0); }
    bool is_done() const { return (remaining_opens() == 0 && open_balance() == 0); }
    bool has_only_closes_left() const { return (remaining_opens() == 0 && remaining_closes() != 0); }

    /**
     * @brief If a valid path can continue with both "(" and ")".
     * Example "(()" can proceed validly with either "(" or ")".
     */
    bool is_time_to_fork() const { return (!is_done() && !is_new() && !has_only_closes_left() && open_balance() > 0); }

    void push_back(std::string symbol)
    {
        if (symbol == "(" ) ++n_opens;
        if (symbol == ")" ) ++n_closes;
        stack.push_back(symbol);
    }

    std::string to_string() const
    {
        std::stringstream ss;
        for (const auto& symbol : stack) {
            ss << symbol;
        }
        return ss.str();
    }
    
private:
    int max_opens;
    int n_opens;
    int n_closes;
    std::vector<std::string> stack;
};

using Paths = std::vector<Path>;

Path take_next_step(Path path, std::string next_step = "(")
{
    if (path.is_done()) {}                  // Nothing to be done
    else if (path.is_new()) {
        path.push_back("(");                // Start of new path must be  (
    }
    else if (path.has_only_closes_left()) {
        path.push_back(")");                // Start to close
    }
    else {
        path.push_back(next_step);          // This is a fork in the road, the path will bisect, so use whatever is passed in
    }
    return path;
}

Paths recursive_expand(Paths paths)
{
    // Recursive base case: All paths are done
    if (std::all_of(paths.begin(), paths.end(), [](const Path& p){ return p.is_done(); } )) {
        return paths;
    }

    // Not all paths are done: Advance all paths by a step
    Paths forks;

    for (auto& path : paths) {
        if (path.is_time_to_fork()) {
            forks.push_back(take_next_step(path, ")"));                 // fork right )
        }
        path = take_next_step(path);                                    // fork left (, or just default left (
    }

    if (forks.size() > 0)
        std::move(forks.begin(), forks.end(), std::back_inserter(paths));   // merge any forks into paths
    
    // Expand again until all paths are done...
    return recursive_expand(paths);
}

Solution::ReturnValueType Solution::generateParenthesis(InputValueType n)
{        
    Paths paths {Path(n)};              // depth n problem
    paths = recursive_expand(paths);    // create all pairs of well-formed parenthesis combinations for depth-n

    ReturnValueType parens;             // store in required format
    for (const auto& p : paths) {
        parens.push_back(p.to_string());
        std::cout << p.to_string() << std::endl;
    }
    return parens;
}

} // namespace