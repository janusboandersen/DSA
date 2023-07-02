/**
 * @file test/testcases/36/test_valid_sudoku.cpp
 * @author Janus Bo Andersen
 * @brief Tests for Leetcode problem 36
 * @version 1.0
 * @date 2023-06-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <36/valid_sudoku.hpp>

using namespace testing;
using namespace p36;

using Board = std::vector<std::vector<char>>;

class p36_ConstraintsAndExamples: public Test {
public:
    Solution solution;
    Board board1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool validity1 = true;

    Board board2 = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    bool validity2 = false;

};

TEST_F(p36_ConstraintsAndExamples, TestCase1_MatchesExample) {
    EXPECT_EQ(solution.isValidSudoku(board1), validity1);
}

TEST_F(p36_ConstraintsAndExamples, TestCase2_MatchesExample) {
    EXPECT_EQ(solution.isValidSudoku(board2), validity2);
}