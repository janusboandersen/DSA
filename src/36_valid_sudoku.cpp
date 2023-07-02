/**
 * @file src/36_valid_sudoku.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 36
 * @version 1.0
 * @date 2023-06-22
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <unordered_map>
#include <functional>
#include <36/valid_sudoku.hpp>

namespace p36 {

using Board = std::vector<std::vector<char>>;
using Slice = std::vector<char>;
using UniqueMap = std::unordered_map<char, int>;

void print_slice(const Slice& vec, std::string v_name = "v")
{
    auto n {vec.size()};
    std::cout << v_name << " = {";
    for (const auto& e : vec)
        std::cout << e << (--n ? ", " : "");
    std::cout << "};\n";
}

/**
 * @brief Extract one of the 9 columns from a Sudoku board.
 */
Slice col(Board& board, std::size_t col_num) 
{
    Slice column_slice;
    for (const auto& row : board) {
        column_slice.push_back(row[col_num]);   // grab the col'th element of each row to produce a full column
    }
    return column_slice;
}

/**
 * @brief Extract one of the 9 rows from a Sudoku board.
 */
Slice row(Board& board, std::size_t row_num) {
    return board[row_num];                      // return the row'th row
}

/**
 * @brief Extract one of the 9 sub-boxes from a Sudoku board.
 * Box_num:
 * | 0 | 1 | 2 |  < Rows 0-2
 * | 3 | 4 | 5 |  < Rows 3-5
 * | 6 | 7 | 8 |  < Rows 6-8
 *   ^   ^   ^
 *  0-2 3-5 6-8
 */
Slice box(Board& board, std::size_t box_num) {
    Slice box_slice;
    Board::iterator row_begin = board.begin() + (box_num / 3) * 3;            // E.g. box 4 -> [4 / 3] * 3 = 1 * 3 = 3. Box 4 correctly begins at board row 3.
    Board::iterator row_end = row_begin + 3;                                  // E.g. box 4 -> ends at board row 5 (and end is one-past, like all iterators in C++)
    std::size_t col_begin = (box_num % 3) * 3;                                // E.g. box 4 -> (4 % 3)*3 = 1*3 = 3. Box 4 correctly begins at board col 3.
    std::size_t col_end = col_begin + 3;

    for (auto row = row_begin; row != row_end; ++row) {
        for (auto col = col_begin; col != col_end; ++col) {
            box_slice.push_back(row->at(col));
        }
    }

    return box_slice;                      
}

/**
 * @brief Test validity of slice. A slice is valid iff. there are no duplicates of "1"-"9".
 */
bool is_valid_slice(Slice& slice)
{
    UniqueMap map;
    for (auto s : slice) {
        if (s == '.') continue;             // ignore missing
        if (++map[s] > 1) return false;     // found a duplicate
    }
    return true;                            // didn't find duplicates
}

/**
 * @brief Test validity of all slices extracted using slice_getter (e.g. function col) from the Sudoku board.
 */
bool is_all_valid(std::function<Slice(Board&, std::size_t)> slice_getter, Board& board) {
    for (std::size_t idx = 0; idx < 9; ++idx) {             // across all rows, cols, or boxes
        auto this_slice = slice_getter(board, idx);         // invoke the passed function to extract a slice
        if (!is_valid_slice(this_slice)) return false;      // end iteration early if one of the slices isn't valid
    }
    return true;
}

/**
 * @brief Test if current board configuration obeys validity rules. Does not determine whether board is in fact solvable.
 */
Solution::ReturnValueType Solution::isValidSudoku(Solution::InputValueType& board)
{
    // Board is valid iff all rows are valid, all cols are valid, all boxes are valid
    return is_all_valid(col, board) && is_all_valid(row, board) && is_all_valid(box, board);
}

} // namespace