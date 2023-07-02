/**
 * @file src/include/49/group_anagrams.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 49: Group anagrams
 * 
 * Given an array of strings strs, group the anagrams together. 
 * You can return the answer in any order. 
 * An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 * 
 * Strategy idea 1: O(M*N*n) for M groups of anagrams, from list of N words of average length n.
 *  Use method for checking anagrams from prob. 242
 *  Brute-force through the input vector as long as there are words (size > 0):
 *   Pop-off back word -> w -> group_vector
 *    Check remainder of input vector to w: is_anagram(w, *it)
 *    Any anagrams are added to group_vector and erased from input vector
 *  Conclusion: TOO SLOW for LeetCode, stuck on test case 111.
 * 
 * Strategy idea 2: O(N * n lg n) for N words of average length n
 *  Notice that two words are anagrams iff. their sorted values are equal, e.g. nat->ant and tan->ant
 *  Use this method to check, i.e. sorted(word1) == sorted(word2) is an anagram
 *  Use rest of brute-force from strategy 1
 *  Conclusion: TOO SLOW for LeetCode, stuck on test case 111.
 * 
 * Strategy idea 3: O(N * n lg n + M) for M groups of anagrams, from list of N words of average length n.
 *  Use hashmap collisions to form groups:
 *   Traverse input list: O(N)
 *   Sort each word: O(n lg n)
 *   Insert word into back of vector inside hashmap: O(1)
 *   Collapse hashmap into a final result vector of vectors: O(M)
 *     - For a little extra speed, std::move the vectors from the hashmap to the result vector.
 *  Conclusion: Faster than 94% of other solutions-
 * 
 * @version 1.0
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>

#pragma once

namespace p49 {

class Solution {
public:
    using InputValueType = std::vector<std::string>;
    using ReturnValueType = std::vector<InputValueType>;
    
    ReturnValueType groupAnagrams(InputValueType& strs);
};

} // namespace