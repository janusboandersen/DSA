/**
 * @file src/128_longest_consecutive_sequence.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 128
 * @version 1.0
 * @date 2023-06-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <unordered_set>
#include <128/longest_consecutive_sequence.hpp>

namespace p128 {

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

template <typename T>
T max_val(const T& a, const T& b)
{
    return (a >= b ? a : b);
}

using Set = std::unordered_set<int>;

/**
 * @brief Check if set contains the element that precedes it on the integer number line.
 * E.g. has_left_neighbour(2, my_set) only returns true of 1 is contained in my_set.
 */
inline bool has_left_neighbor(const int& element, const Set& set)
{
    return (set.count(element-1) > 0);
}

/**
 * @brief Sequence semantics. The start of a sequence has no left neighbor on the integer number line.
 */
inline bool is_sequence_start(const int& element, const Set& set)
{
    return (!has_left_neighbor(element, set));
}

/**
 * Recursively check sequence length from element on the integer number line.
 */
int sequence_length (const int& element, const Set& set)
{
    // base case, element is not in set, so sequence from here is of length zero
    if (set.count(element) == 0) return 0;

    // recursive case, element is in sequence, find length of sequence for next element on integer number line.
    return 1 + sequence_length(element+1, set);
}

Solution::ReturnValueType Solution::longestConsecutive(Solution::InputValueType& nums)
{
    Set set (nums.begin(), nums.end());                                     // Create a set from the input vector
    int max_length = 0;                                                     // Keep track of the length of the longuest seq. seen so far

    for (const auto& element : nums) {
        if (is_sequence_start(element, set)) {
            max_length = max_val(max_length, sequence_length(element, set));    // Check the length of this new seq.
        }
    }

    return max_length;
}

} // namespace