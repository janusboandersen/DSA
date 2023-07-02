/**
 * @file src/155_min_stack.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 155
 * @version 1.0
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <155/min_stack.hpp>

namespace p155 {

MinStack::MinStack() {}

void MinStack::push(int val)
{
    if (value_stack.size() == 0)
        min_value_stack.push(val);                                  // Stack is empty, so no minimum value to compare to, just push it straight on as newest min value.

    if (min_value_stack.size() > 0 && val <= min_value_stack.top()) // Stack is already in use, and need to make comparison whether to record new min_value
        min_value_stack.push(val);                                  // The old min gets pushed down and will become relevant again once this new element is pop'ed

    value_stack.push(val);
}

void MinStack::pop()
{
    if (value_stack.size() == 0) return;    // Can't do anything

    if (value_stack.top() == min_value_stack.top())
        min_value_stack.pop();              // Removing the current min. value, so need to restore a previous min_value to the top.

    value_stack.pop();
}

int MinStack::top()
{
    return value_stack.top();               // Top of the MinStack is just the top of the internal value stack, NOT necessarily a minimum value.
}

int MinStack::getMin()
{
    return min_value_stack.top();           // Top of this stack is always == smallest current value in the value_stack
}

} // namespace