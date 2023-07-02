/**
 * @file src/49_group_anagrams.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 49
 * @version 1.0
 * @date 2023-06-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <49/group_anagrams.hpp>

namespace p49 {

using Map = std::unordered_map<std::string, std::vector<std::string>>;

Solution::ReturnValueType Solution::groupAnagrams(InputValueType& strs)
{
    ReturnValueType groups;
    Map map;
    std::string sorted;

    // Process each word, N words of avg. length n: O( N * n * lg n )
    // -- this is O(N) for traversing vector, and O(n lg n) for sorting each word
    // To speed this up, use a cheaper hashing method than sorting
    for (auto& word : strs) {
        sorted = word;
        std::sort(sorted.begin(), sorted.end());
        map[sorted].push_back(word);                // use collision of sorted words to create groups
    }

    // Collapse the map to a vector of vectors -- M groups, so O(M)
    for (auto& item : map) {
        groups.push_back(std::move(item.second));
    }

    return groups;

}

} // namespace