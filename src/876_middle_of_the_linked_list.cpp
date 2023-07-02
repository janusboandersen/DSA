/**
 * @file 876_middle_of_the_linked_list.cpp
 * @author Janus
 * @brief Solution to LeetCode prob. 876
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <876/middle_of_the_linked_list.hpp>

namespace p876 {

/**
 * @brief Singly-linked list
 */
ListNode::ListNode() : val(0), next(nullptr) {}

ListNode::ListNode(int x) : val(x), next(nullptr) {}

ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {}

ListNode::ListNode(std::initializer_list<int> val_list) : next(nullptr) {
    this->val = *val_list.begin();  // fill this node with the first value
    for (auto it = val_list.begin() + 1; it != val_list.end(); it++) { this->push_back(*it); }  // Insert remaining values in rest of list: Each insertion is O(n)
}

void ListNode::push_back(int val) {
        if (!this->next) { this->next = new ListNode(val); }    // this is the last node in the list, push onto here
        else { this->next->push_back(val); }                    // not last node, try to find back node recursively
}

void destroy(ListNode* &ptr) {
    if (ptr == nullptr) { return; }         // don't try to free nullptr
    if (ptr->next) { destroy(ptr->next); }  // recursively destroy rest of list before deleting this object
    delete ptr;                             // delete this object now
    ptr = nullptr;                          // set callers pointer to nullptr
}

Solution::ReturnValueType Solution::middleNode(Solution::InputValueType head) {
    
    if (head == nullptr) { return nullptr; };       // Corner case: Empty list
    if (head->next == nullptr) { return head; };    // Simple case: 1-element list

    // Iteration case: 2 or more nodes.
    // Method: trav1 advances one step, trav2 advances two steps. Stop when trav2 sees the last node.
    // At zero iterations: trav1 == trav2 at loc. i = 0.
    // After n iterations:
    // - trav1 is at loc. i = n   [ 0  1  2  3  4 ...  n ... N-1 ]
    // - trav2 is at loc. i = 2n  [ 0  1  4  6  8 ... 2n ...     ]
    //
    // Case A: Uneven number of nodes - there exists a single middle node:
    // E.g. N = 5 (middle = node(5/2) = node(2). Last node is node(N-1) = node(4) ):
    // After n = 2 iterations:
    // - trav1 is at node(i = 2), which is the middle node in the sequence (0 1 _2_ 3 4).
    // - trav2 is at node(i = 4), and sees node(i)->next==nullptr. This must stop iteration.
    // 
    // Case B: Even number of nodes - there are two middle nodes:
    // E.g. N = 6 (middle = node(6/2) = node(3). Last node is node(N-1) = node(5) ):
    // After n = 3 iterations:
    // - trav1 is at node(i = 3), which is second-middle of sequence (0 1 2 _3_ 4 5).
    // - trav2 is at node(i = 6) which is PAST THE END.
    //   HOW TO DETECT? One iteration earlier trav2 at node(i = 4) and could see node(i)->next->next==nullptr.
    
    auto trav1 = head;  // points to node(i = 0).
    auto trav2 = head;
    
    while (trav2 != nullptr && trav2->next != nullptr) {
        trav1 = trav1->next;        // one step
        trav2 = trav2->next->next;  // two steps
    }
    return trav1;
}

} // namespace
