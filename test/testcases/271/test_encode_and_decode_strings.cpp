/**
 * @file test/testcases/271/test_encode_and_decode_strings.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 271
 * @version 1.0
 * @date 2023-06-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <271/encode_and_decode_strings.hpp>

using namespace testing;
using namespace p271;

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

class p271_ConstraintsAndExamples: public Test {
public:
    Solution solution;
    std::vector<std::string> ex1_data { "lint", "code", "love", "you" };
    std::vector<std::string> ex2_data { "we", "say", ":", "yes" };
};

TEST_F(p271_ConstraintsAndExamples, TestCase2_Roundtrip_MatchesInputData) {
    auto encoded = solution.encode(ex2_data);
    EXPECT_EQ(solution.decode(encoded), ex2_data);
}
