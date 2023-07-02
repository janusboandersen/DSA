/**
 * @file src/242_valid_anagram.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 242
 * @version 1.0
 * @date 2023-06-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <unordered_map>
#include <242/valid_anagram.hpp>

namespace p242 {

using Dictionary = std::unordered_map<char, int>;

/**
 * @brief Returns Dictionary with a count of the character for the vocabulary string.
 */
Dictionary to_dict(const std::string& vocabulary)
{
    Dictionary dict;
    for (const auto& c : vocabulary) {
        dict[c]++;
    }
    return dict;
}

/**
 * @brief dictA is identical to dictB iff. for every element in dictA, there is an equal cardinality in dictB AND there are no further items in dictB that aren't in dictA (same set).
 */
bool is_identical(Dictionary&& dictA, Dictionary&& dictB)
{
    if (dictA.size() != dictB.size()) { return false; }                 // Different underlying sets of letters
    for (const auto& record : dictA) {
        if (dictB[record.first] != record.second ) { return false; }    // incorrect cardinality of this letter
    }
    return true;                                                        // dictA == dictB
}

/**
 * @brief True if t is an anagram of s. Otherwise false.
 */
Solution::ReturnValueType Solution::isAnagram(InputValueType s, InputValueType t)
{
    if (s == t) return true;                        // identical strings
    if (s.size() != t.size()) return false;         // anagram impossible if uneqal number of characters
    return is_identical(to_dict(s), to_dict(t));
}

} // namespace