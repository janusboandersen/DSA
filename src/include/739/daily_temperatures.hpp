/**
 * @file src/include/739/daily_temperatures.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 739: Daily temperatures
 * 
 * Given an array of integers temperatures represents the daily temperatures, 
 * return an array answer such that answer[i] is the number of days you have 
 * to wait after the ith day to get a warmer temperature. 
 * 
 * If there is no future day for which this is possible, keep answer[i] == 0 instead.
 * 
 * Brute-force solution ~O(n^2):
 * - For each temp[i], search remainder of list for temp[j]>temp[i] (j>i).
 * - If found, res[i]=j-i, otherwise res[i]=0.
 * Problem: This fails for very large datasets. Need a better algo.
 * 
 * Stack-based solution ~O(n):
 * - Keep storing unpaired daily temp. observations on the stack until we reach a day where temp[today] > temp[some_prev_day].
 * - Then pop off the items with stack.top().temp < temp[today], and store day_diff in results.
 * 
 * TODAY  TEMPERATURES           STACK                           RESULT                                 COMMENT
 *        [10 9 8 7 9 10 11]     Observation(day, temp)          Vector<day_diff(today-some_prev_day)>
 *   0 -----^                    | (0,10) |                      <  0,   0,   0,   0,   0,   0, 0>      Push unpaired temp. observation on the stack as stack empty.
 *   1 -------^                  | (0,10) (1,9) |                <  0,   0,   0,   0,   0,   0, 0>      Push unpaired temp. observation on the stack as temp[today] < temp[yesterday]
 *   2 ---------^                | (0,10) (1,9) (2,8) |          <  0,   0,   0,   0,   0,   0, 0>      Push unpaired temp. observation on the stack as temp[today] < temp[yesterday]
 *   3 -----------^              | (0,10) (1,9) (2,8) (3,7) |    <  0,   0,   0,   0,   0,   0, 0>      Push unpaired temp. observation on the stack as temp[today] < temp[yesterday]
 *   4 -------------^            | (0,10) (1,9) (4,9) |          <  0,   0, 4-2, 4-3,   0,   0, 0>      Popping (3,7) and then (2,8) because both smaller than temp[today=4]==9
 *   5 ---------------^          | (0,10) (5,10) |               <  0, 5-1,   2,   1, 5-4,   0, 0>      Popping (4,9) and then (1,9) because both smaller than temp[today=5]==10
 *   6 ------------------^       | (6,11) |                      <6-0,   4,   2,   1,   1, 6-5, 0>      Popping (5,10) and then (0,10) because both smaller than temp[today=6]==11
 * 
 *                                                               <  6,   4,   2,   1,   1,   1, 0>      Halt, no more temperatures to compare to.
 * @version 1.0
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>

#pragma once

namespace p739 {

class Solution {
public:
    using InputValueType = std::vector<int>;
    using ReturnValueType = std::vector<int>;
    ReturnValueType dailyTemperatures(InputValueType& temperatures);        // stack-based
    ReturnValueType dailyTemperatures_bf(InputValueType& temperatures);     // brute-force
};

} // namespace