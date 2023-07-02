/**
 * @file src/include/36/valid_sudoku.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 36: Valid sudoku
 * 
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
 * 
 * Note:
 * A Sudoku board (partially filled) could be valid but is not necessarily solvable.
 * Only the filled cells need to be validated according to the mentioned rules.
 * 
 * Solution strategy:
 *   - Look for "no duplicates" of "1"-"9" across the
 *     - 9 rows,
 *     - 9 columns, and
 *     - 9 boxes.
 * 
 * @version 1.0
 * @date 2023-06-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>

#pragma once

namespace p36 {

class Solution {
public:
    using InputValueType = std::vector<std::vector<char>>;
    using ReturnValueType = bool;
    ReturnValueType isValidSudoku(InputValueType& board);
};

} // namespace