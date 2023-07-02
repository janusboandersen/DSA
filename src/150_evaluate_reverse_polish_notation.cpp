/**
 * @file src/150_evaluate_reverse_polish_notation.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 150
 * @version 1.0
 * @date 2023-06-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <150/evaluate_reverse_polish_notation.hpp>

namespace p150 {

template <typename T>
void print_vector(const std::vector<T>& v)
{
    int n = v.size()-1;
    std::cout << "v = {";
    for (const auto& elem : v) {
        std::cout << elem << (n-- ? ", " : "");
    }
    std::cout << "}" << std::endl;
}

/**
 * @brief Binary addition.
 */
int iplus(int a, int b)
{
    return a + b;
}

/**
 * @brief Binary subtraction.
 */
int iminus(int a, int b)
{
    return a - b;
}

/**
 * @brief Binary Multiplication.
 */
int imult(int a, int b)
{
    return a * b;
}

/**
 * @brief Binary integer division.
 */
int idiv(int a, int b)
{
    return a / b;
}

/**
 * @brief Maintain the stack in ints
 */
using Stack = std::stack<int>;


/**
 * @brief Pops a value and returns it from stack.
 */
inline int popr(Stack& s)
{
    auto val = s.top();
    s.pop();
    return val;
}


Solution::ReturnValueType Solution::evalRPN(Solution::InputValueType& tokens)
{
    // Math operation semantics
    const std::unordered_set<std::string> operators {"+", "-", "*", "/"};
    auto is_operator = [&operators](const std::string& token){ return (operators.count(token) > 0); };  // True if the token is an operator, otherwise false.
    std::unordered_map<std::string, std::function<int(int, int)>> operation_for {{"+", iplus}, {"-", iminus}, {"*", imult}, {"/", idiv}};
    
    Stack operands;
    std::string token;
    int op_a;
    int op_b;

    // Read tokens left-to-right
    for (const auto& token : tokens) {
        if(is_operator(token)) {
            // pop off two operands
            op_b = popr(operands);
            op_a = popr(operands);

            //perform operation and push result back on the stack
            operands.push(operation_for[token](op_a, op_b));

        } else {
            // push operand on to stack
            operands.push(std::stoi(token));
        }
    }
    
    // return remaining element on the stack as the result
    return operands.top();
}

} // namespace