/**
 * @file src/include/271/encode_and_decode_strings.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 271: Encode and decode strings
 * 
 * Design an algorithm to encode a list of strings to a string. 
 * The encoded string is then sent over the network and is decoded back to the original list of strings.
 * 
 * @version 1.0
 * @date 2023-06-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>

#pragma once

namespace p271 {

class Solution {
public:
    static std::string encode(std::vector<std::string>& strs);
    static std::vector<std::string> decode(std::string& str);
};

} // namespace