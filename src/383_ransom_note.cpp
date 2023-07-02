/**
 * @file 383_ransom_note.cpp
 * @author Janus
 * @brief Solution to LeetCode prob. 383
 * @version 0.1
 * @date 2023-06-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <unordered_map>
#include <iostream>
#include <sstream>
#include <383/ransom_note.hpp>

namespace p383 {

using Dictionary = std::unordered_map<char, int>;

/**
 * @brief Returns Dictionary with a count of the character for the vocabulary string.
 */
Dictionary to_dict(const std::string& vocabulary) {
    Dictionary dict;
    for (const auto& c : vocabulary) {
        dict[c] += 1;
    }
    return dict;
}

std::string to_fmt_string(const Dictionary& dict) {
    std::stringstream s;
    for (const auto& item : dict) {
        s << item.first << "->" << item.second << '\n';
    }
    return s.str();
}

/**
 * @brief super_dict covers sub_dict iff. for every element in sub_dict, there is an equal or higher cardinality in super_dict.
 */
bool is_covered(Dictionary&& sub_dict, Dictionary&& super_dict) {       // requires non-const or copy as [] may mutate super_dict
    for (const auto& item : sub_dict) {
        if (super_dict[item.first] < item.second ) { return false; }    // insufficient of this character
    }
    return true;
}

Solution::ReturnValueType Solution::canConstruct(Solution::InputValueType ransomNote, Solution::InputValueType magazine) {
    // The cardinality of a letter in magazine must be greater than the number of duplicates of that letter in ransomNote.
    // E.g. if ransomNote uses 2 'a' letters, magazine must have at least 2 'a' letters.
    // Best approach seems to be to use an unordered map to count the occurrences of each letter in ransomNote, then check against same for magazine.
    return is_covered(to_dict(ransomNote), to_dict(magazine));
}

} // namespace
