/**
 * @file src/include/155/min_stack.hpp
 * @author Janus Bo Andersen
 * @brief LeetCode problem 155: Min stack
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * 
 * Implement the MinStack class:
 *  MinStack() initializes the stack object.
 *  void push(int val) pushes the element val onto the stack.
 *  void pop() removes the element on the top of the stack.
 *  int top() gets the top element of the stack.
 *  int getMin() retrieves the minimum element in the stack.
 * 
 * You must implement a solution with O(1) time complexity for each function.
 * 
 * Obvious choice to use a stack for storing the incoming values.
 * The "trick" here seems to be HOW to always keep track of the MINIMUM value, so as to avoid linear searching for the min-element.
 * - When a new element is the smallest, we need to record that as the current-smallest.
 * - When an element with the min value is popped, we need to know the "next in line" min value in O(1).
 * - "Problem" is knowing "next in line" min. value in O(1). 
 * - Perhaps using a stack that keeps track of past min values..?
 * - Change-check must be triggered for the operations that modify the stack (push/pop), so current min-values can be recorded/removed.
 * - Several data structures can facilitate O(1) insertion/removal at the end, as well as O(1) access to the last element.
 * - Best to just use built-in stack for both stacks.
 * 
 * Time complexity: O(1) for all operations
 * Space complexity: O(n) for value stack + O(n) for min_value stack ~ O(n) total.
 * 
 * An alternative would be to store pairs on a single stack, such as <Value:int, CurrentMinValue:int>.
 * The top pair then holds both the top value, and the current minimum value.
 * Then, history is preserved in the pair, and popping an element automatically "restores history" to a previous state.
 * However, redundant information is created, as we record something for <..., CurrentMinValue> even when that value isn't changing.
 * 
 * @version 1.0
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stack>

#pragma once

namespace p155 {

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
class MinStack {
public:
    MinStack();
    void push(int val);
    void pop();
    int top();
    int getMin();
private:
    std::stack<int> value_stack;
    std::stack<int> min_value_stack;
};

} // namespace