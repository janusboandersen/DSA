/**
 * @file test_middle_of_the_linked_list.cpp
 * @author Janus
 * @brief Tests for Leetcode problem 876
 * @version 0.1
 * @date 2023-06-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <876/middle_of_the_linked_list.hpp>

using namespace testing;
using namespace p876;

class p876_ConstraintsAndExamples: public Test {
public:
    Solution solution;

    ListNode* test_list_0 = new ListNode {1, 2, 3, 4, 5};
    ListNode* middle_list_0 = test_list_0->next->next;          // middle node {3,4,5}
    
    ListNode* test_list_1 = new ListNode {1, 2, 3, 4, 5, 6};
    ListNode* middle_list_1 = test_list_1->next->next->next;    // tie, second middle node {4,5,6}

    ListNode* corner_case_empty = nullptr;
    ListNode* corner_case_one_node = new ListNode {1};

    ~p876_ConstraintsAndExamples() {
        // destroy whole list to prevent memory leaks
        destroy(test_list_0);
        destroy(test_list_1);
        destroy(corner_case_empty);
        destroy(corner_case_one_node);
    }
};

TEST_F(p876_ConstraintsAndExamples, TestList0_ReturnsExamplePointer) {
    EXPECT_EQ(solution.middleNode(test_list_0), middle_list_0);
}

TEST_F(p876_ConstraintsAndExamples, TestList1_ReturnsExamplePointer) {
    EXPECT_EQ(solution.middleNode(test_list_1), middle_list_1);
}

TEST_F(p876_ConstraintsAndExamples, CornerCase_EmptyList_ReturnsNullPtr) {
    EXPECT_EQ(solution.middleNode(corner_case_empty), nullptr);
}

TEST_F(p876_ConstraintsAndExamples, CornerCase_OneNodeList_ReturnsFirstNode) {
    EXPECT_EQ(solution.middleNode(corner_case_one_node), corner_case_one_node);
}