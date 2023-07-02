/**
 * @file src/271_encode_and_decode_strings.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 271
 * @version 1.0
 * @date 2023-06-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <sstream>
#include <271/encode_and_decode_strings.hpp>

namespace p271 {

class Serializer 
{
public:

    /**
     * @brief Serializes into a string, inserting the newline character as separator token.
     */
    static std::string serialize(std::vector<std::string> strs)
    {
        std::string sep_token {"\n"};
        std::stringstream ss;
        auto n {strs.size()};
        for (const auto& str : strs)
            ss << str << (--n ? sep_token : "");
        return ss.str();
    }

    /**
     * @brief Deserializes a string, expecting the newline character as separator token.
     */
    static std::vector<std::string> deserialize(std::string& str)
    {
        std::vector<std::string> deserialized;      // result will be built here
        std::string word;
        std::stringstream ss;
        ss << str;                                  // load the network string into a stream to consume piecemeal later

        while (std::getline(ss, word))              // read an entire line, a string can contain whitespaces
        {
            deserialized.push_back(word);
        }
        return deserialized;
    }
};

/**
 * @brief Encode arrays of strings into network-transmittable string.
 * @param strs: a list of strings
 * @return: encodes a list of strings to a single string.
 */
std::string Solution::encode(std::vector<std::string>& strs)
{
    return Serializer::serialize(strs);
}

/**
 * @brief Decode a string from the network into an array of strings.
 * @param str: A string
 * @return: decodes a single string to a list of strings
 */
std::vector<std::string> Solution::decode(std::string& str)
{
    return Serializer::deserialize(str);
}

} // namespace