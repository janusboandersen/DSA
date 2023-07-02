/**
 * @file middle_of_the_linked_list.hpp
 * @author Janus
 * @brief LeetCode problem 876: Middle of the Linked List
 * 
 * Given the head of a singly linked list, return the middle node of the linked list.
 * If there are two middle nodes, return the second middle node.
 * 
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <initializer_list>

namespace p876 {

/**
 * @brief Singly-linked list
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode();
    ListNode(int x);
    ListNode(int x, ListNode *next);
    ListNode(std::initializer_list<int> val_list);
    void push_back(int val);
};

void destroy(ListNode* &ptr);

class Solution {
public:
    using ReturnValueType = ListNode*;
    using InputValueType = ReturnValueType;
    ReturnValueType middleNode(InputValueType head);
};

} // namespace
