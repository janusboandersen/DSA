/**
 * @file src/238_product_of_array_except_self.cpp
 * @author Janus Bo Andersen
 * @brief Solution to LeetCode prob. 238
 * @version 1.0
 * @date 2023-06-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <238/product_of_array_except_self.hpp>

namespace p238 {

void print_vector(const std::vector<int>& vec, std::string v_name = "v")
{
    auto n {vec.size()};
    std::cout << v_name << " = {";
    for (const auto& e : vec)
        std::cout << e << (--n ? ", " : "");
    std::cout << "};\n";
}

/**
 * @brief O(n)-time and O(n)-space implementation using two sliding windows, which are computed sort-of recursively:
 * - one window holds product of all elements behind of elem. i, 
 * - other windown holds product of all elements ahead of elem. i.
 * -> product_except_self[i] ::= behind_of[i] * ahead_of[i]
 * 
 * nums              [  1   2   3   4  ]
 * behind_of i       [  x   1   2   6  ]
 * ahead_of i        [  24  12  4   x  ]
 * prod_exc_self     [  24  12  8   6  ]
 * 
 * The x's are initialized to 1 (the multiplicative identity), so they have no impact on whatever they are multiplied with.
 * 
 * The windows are computed in one loop over the input vector -> O(n).
 * The product is computed in one loop over the output vector -> O(n).
 * Total time complexity is O(n+n) ~ O(n).
 */
std::vector<int> Solution::productExceptSelf(std::vector<int>& nums)
{
    std::size_t N = nums.size();
    std::vector<int> behind_of (N);
    std::vector<int> ahead_of (N);
    std::vector<int> product_except_self (N);               // stores result

    // Window initialization
    behind_of[0] = ahead_of[N-1] = 1;                       // multiplicative identity

    // Compute sliding windows, O(N)
    for (std::size_t i = 1, j = N-1-i; i < N; ++i, j = N-1-i) {
        // j is iterating in reverse from N-2, ..., 0
        behind_of[i] = behind_of[i-1] * nums[i-1];          // trailing window
        ahead_of[j] = ahead_of[j+1] * nums[j+1];            // leading window
    }

    // Compute product result, O(N)
    for (std::size_t i = 0; i < N; ++i) {
        product_except_self[i] = behind_of[i] * ahead_of[i];
    }

    return product_except_self;
}

/**
 * @brief Alternative O(n)-time and O(1)-space implementation (ex. result vector)
 * - Change 1: Compute result inside the same loop that computed windows:
 *   - (forward direction) result[i] = result[i] * behind_of[i], 
 *   - (reverse direction) result[j] = result[j] * ahead_of[j].
 * - Change 2: Using two running products instead of separate arrays, while making the two passes over the input vector (forward + backward).
 * 
 * ITER.      FWD PROD    BCKW PRoD     RESULT CONSTR.
 * (init).    <>        , ||.           result = {  x         ,  x           ,  x           ,  x          };  // x = initialization value of result = 1
 * (i=1,j=2). <1>       , |4|.          result = {  x         ,  x*<1>       ,  x*|4|       ,  x          };
 * (i=2,j=1). <1*2>     , |4*3|.        result = {  x         ,  x*<1>*|4*3| ,  x*<1*2>*|4| ,  x          };
 * (i=3,j=0). <1*2*3>   , |4*3*2|.      result = {  x*|4*3*2| ,  x*<1>*|4*3| ,  x*<1*2>*|4| ,  x*<1*2*3>  };
 * (result).                            result = {  24        ,  12          ,  8           ,  6          };
 * <...>: Product built up by forward pass ::= tail product
 * |...|: Product built up by reverse pass ::= head product
 * 
 */
std::vector<int> Solution::productExceptSelf_alt(std::vector<int>& nums)
{
    std::size_t N = nums.size();
    std::vector<int> result (N, 1);

    // Product initializations, mult. ident. like before
    int tail_product = 1;
    int head_product = 1;

    for (std::size_t i = 1, j = N-1-i; i < N; ++i, j = N-1-i) {
        // j is iterating in reverse from N-2, ..., 0
        tail_product *= nums[i-1];      // Forward-constructed product
        head_product *= nums[j+1];      // Reverse-constructed product

        result[i] = result[i] * tail_product;
        result[j] = result[j] * head_product;
    }

    return result;
}

/**
 * @brief Alternative 2: Binomial expansion
 * 
 * Soln. 2 feels a bit like a binomial expansion. 
 * There are 3 free terms (product except self, so 4-1). Notice: 
 * (a+b)^3 = c0*a^3 + c1*a^2*b + c2*a*b^2 + c3*b^3, where the binomial thm. coefficients are ci = C(n, i).
 * Or, in general, for (a+b)^n, the i'th ordered term is p(i) = C(n, i) * a^(n-i) * b^(i).
 * 
 * If "a to power n" (a^n) means product of n terms from list a, and we ignore the binomial coefficients, then
 * we have the expansion: "(a+b)^3" ::= a0*a1*a2, a0*a1*b0, a0*b0*b1, b0*b1*b2.
 * and the i'th term is p(i) = a^(n-i) * b^(i).
 * I.e., we could determine the i'th value formulaically, without explicitly iterating over the input vector, but instead doing recursion.
 *
 * Example: Let ai ::= reverse({1,2,3,4})={4,3,2,1} and bi ::= {1,2,3,4}, with i = 0,1,2,3 and n = N-1 = 3.
 * Then, power terms are: 
 *  p(0) = a^(3)*b^(0) = a0*a1*a2 = (4*3*2)   = 24, 
 *  p(1) = a^(2)*b^(1) = a0*a1*b0 = (4*3)*(1) = 12, 
 *  p(2) = a^(1)*b^(2) = a0*b0*b1 = (4)*(1*2) = 8, 
 *  p(3) = a^(0)*b^(3) = b0*b1*b2 = (1*2*3)   = 6.
 * So, result = {24, 12, 8, 6}.
 * 
 * Interesting idea: Could also reduce the products to sums by taking the logarithm, and then subtracting out the "self".
 * 
 */
class BinomialExpansion
{
public:
    BinomialExpansion(const std::vector<int>& data) : N{data.size()}, m_data{data} {}

    int a(int power)
    {
        // reverse powers
        if (power == 0) return 1;
        return m_data[(N-1) - (power-1)] * a(power-1);
    }

    int b(int power)
    {
        // forward powers
        if (power == 0) return 1;
        return m_data[(power-1)] * b(power-1);
    }

    int p(int i)
    {
        // binomial product expansion at index i
        return a((N-1)-i) * b(i);
    }

    const std::size_t N;

private:
    const std::vector<int> m_data;
};

/**
 * @brief Implements solution using the binomial expansion.
 */
std::vector<int> Solution::productExceptSelf_alt2(std::vector<int>& nums)
{
    auto binom = BinomialExpansion(nums);
    std::vector<int> result;

    for (std::size_t i = 0; i < binom.N; ++i) {
        result.push_back(binom.p(i));
    }

    return result;
}


} // namespace