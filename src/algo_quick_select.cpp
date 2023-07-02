/**
 * @file src/algo_quick_select.cpp
 * @author Janus Bo Andersen
 * @brief Implementation of quick-select algorithm
 * @version 1.0
 * @date 2023-06-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <algorithm>
#include <algo/quick_select.hpp>

namespace algo {
namespace qs {

/**
 * @brief Partitions container in-place using last element as pivot, and returns iterator pointing at the first item after the partition boundary.
 * Items before the partition boundary are less than or equal to the pivot (<=), and items after the partition boundary are greater than the pivot (>).
 * The final item in the first group is equal to the pivot.
 * There is no further order within the two groups.
 */
Iterator qs_partition(Iterator begin_at, Iterator end_at)
{
    if (begin_at >= end_at) { return begin_at; }    // nothing to be done: No data (==), or algorithm doesn't work in reverse direction (>).
    auto pivot = (end_at - 1);                      // choose last element as pivot
    auto gt_start = begin_at;                       // boundary to values greater than pivot (> pivot)
    auto trav = begin_at;                           // this iterator will be traversing the entire range sequentially

    // std::cout << "Pivot is " << *pivot << std::endl;
    while (trav != end_at) {                        // still more partitioning to be done,
        if (*trav <= *pivot) {                      // item found belongs to the first group (<= pivot),
            if (gt_start !=trav) {                  // and there exist(s) some item(s) in the second group (> pivot),
                std::swap(*trav, *gt_start);        // so place the item at the end of the first group (<= pivot),
                // std::cout << "Swapping " 
                // << *gt_start 
                // << " and " 
                // << *trav << std::endl;
            }
            ++gt_start;                             // and expand area demarking first group (<= pivot), residing in [begin_at, gt_start)
        }
        ++trav;                                     // advance to next item
    }
    return gt_start;                                // final partition boundary
}

/**
 * @brief Reorders range in-place such that element pointed to by select_at will be the same as-if range was sorted.
 * - Elements to the left of select_at will all be smaller or equal to element at select_at (but no guarantee on their order).
 * - Elements to the right of select_at will all be equal to or larger than element at select_at (but no guarantee on their order).
 * - Faster than sorting: Expected time complexity O(log n).
 * - Recursive, stack depth max log n.
 *
 * Examples:
 * v = {4, 2, 7, 3}
 * 
 * quick_select(v.begin(), v.begin()+1, v.end())
 * v : {2, 3, 7, 4}
 *         ^
 *        +1
 *
 * quick_select(v.begin(), v.begin()+2, v.end())
 * v : {2, 3, 4, 7}
 *            ^
 *           +2
 */
Iterator quick_select(Iterator begin_at, Iterator select_at, Iterator end_at) {
    if (select_at < begin_at) { select_at = begin_at; }                             // Lower bound, first element
    if (select_at >= end_at) { select_at = end_at - 1; }                            // Upper bound, last element

    auto part = qs_partition(begin_at, end_at);                                     // Partition the range

    // Approach: To have select_at be the correct value for a sorted order, we need partition to be at select_at + 1 (such that select_at is the pivot in the partition).

    // Recursive cases
    if (part < select_at + 1) {return quick_select(part, select_at, end_at);}       // Partition occured before desired location -> only need to quick-select in upper group
    if (part > select_at + 1) {return quick_select(begin_at, select_at, part-1);}   // Partition occured after desired location -> only need to quick-select in lower group, and pivot should not be reused

    // Base case - done - (part == select_at + 1)
    return part;                                                                    // Range must be partitioned exactly at location where used wanted it
}

} // qs
} // algo