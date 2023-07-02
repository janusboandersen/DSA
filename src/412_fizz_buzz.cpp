/**
 * @file 412_fizz_buzz.cpp
 * @author Janus
 * @brief Solution to LeetCode prob. 412
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <412/fizz_buzz.hpp>

namespace p412 {

inline Solution::ValueType transform(int i) {
    Solution::ValueType s = "";
    s += (i % 3 == 0 ? "Fizz" : "");
    s += (i % 5 == 0 ? "Buzz" : "");
    return (s.size() ? s : std::to_string(i));
}

/**
 * @brief Returns vector of fizz-buzz'ed strings
 * 
 * @return int
 */
Solution::Container Solution::fizzBuzz(int n) {
    Container fizz_buzz;
    for (int i = 1; i <=n; i++) {
        fizz_buzz.push_back(transform(i));
    }

    return fizz_buzz;
}

} // namespace
