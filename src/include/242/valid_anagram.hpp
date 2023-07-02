/**
 * @file src/include/242/valid_anagram.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 242: Valid anagram
 * 
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise. 
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 * 
 * Current solution strategy for two length n words: O(3*n) ~ O(n)
 *  Build representation of each word in a hashmap: O(2*n)
 *  Compare the two hashmaps for equality: O(n)

 * See problem 49, a simpler way to check anagrams is to just compare sorted words: cat->act, tac->act, so check sorted(s1)==sorted(s2).
 * For length n word, complexity is O(2*n*logn) ~ O(n logn)
 * 
 * @version 1.0
 * @date 2023-06-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#pragma once
#include <string>

namespace p242 {

class Solution {
public:
    using ReturnValueType = bool;
    using InputValueType = std::string;
    ReturnValueType isAnagram(InputValueType s, InputValueType t);
};

} // namespace