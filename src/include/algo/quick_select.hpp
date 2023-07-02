/**
 * @file src/include/algo/quick_select.hpp
 * @author Janus Bo Andersen
 * @brief Algorithm: Quick select
 * Emits namespace algo::qs
 * 
 * @version 1.0
 * @date 2023-06-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <vector>
#include <functional>


#pragma once

namespace algo {
namespace qs {

using Iterator = std::vector<int>::iterator;
Iterator qs_partition(Iterator begin_at, Iterator end_at);
Iterator quick_select(Iterator begin_at, Iterator select_at, Iterator end_at);

} // qs

namespace qs_template {


template <typename Iterator, typename Compare>
Iterator qs_partition(Iterator begin_at, Iterator end_at, Compare compare)
{
    if (begin_at >= end_at) { return begin_at; }    // nothing to be done: No data (==), or algorithm doesn't work in reverse direction (>).
    auto pivot = (end_at - 1);                      // choose last element as pivot
    auto gt_start = begin_at;                       // boundary to values greater than pivot (> pivot)
    auto trav = begin_at;                           // this iterator will be traversing the entire range sequentially

    // std::cout << "Pivot is " << *pivot << std::endl;
    while (trav != end_at) {                        // still more partitioning to be done,
        if (compare(*trav, *pivot)) {               // item found belongs to the first group (<= pivot),
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


template <typename Iterator, typename Compare>
Iterator quick_select(Iterator begin_at, Iterator select_at, Iterator end_at, Compare compare)
{
    if (select_at < begin_at) { select_at = begin_at; }                             // Lower bound, first element
    if (select_at >= end_at) { select_at = end_at - 1; }                            // Upper bound, last element

    auto part = qs_partition(begin_at, end_at, compare);                         // Partition the range

    // Approach: To have select_at be the correct value for a sorted order, we need partition to be at select_at + 1 (such that select_at is the pivot in the partition).

    // Recursive cases
    if (part < select_at + 1) {return quick_select(part, select_at, end_at, compare);}       // Partition occured before desired location -> only need to quick-select in upper group
    if (part > select_at + 1) {return quick_select(begin_at, select_at, part-1, compare);}   // Partition occured after desired location -> only need to quick-select in lower group, and pivot should not be reused

    // Base case - done - (part == select_at + 1)
    return part;                                                                    // Range must be partitioned exactly at location where used wanted it
}

} // qs_template


} // algo