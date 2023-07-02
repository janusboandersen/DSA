/**
 * @file ransom_note.hpp
 * @author Janus
 * @brief LeetCode problem 383: Ransom Note
 * 
 * Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
 * Each letter in magazine can only be used once in ransomNote.
 * 
 * @version 0.1
 * @date 2023-06-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <initializer_list>
#include <string>

namespace p383 {

class Solution {
public:
    using ReturnValueType = bool;
    using InputValueType = std::string;
    ReturnValueType canConstruct(InputValueType ransomNote, InputValueType magazine);
};

} // namespace
