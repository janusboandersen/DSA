# Data Structures & Algorithms :dizzy:

- Have some fun solving Leetcode challenges.
- Follow the [Neetcode Roadmap :rocket:](https://neetcode.io/roadmap).
- [LeetCode profile](https://leetcode.com/janusboandersen/).
- Detailed algo descriptions are in the header files, key points below.

## Neetcode Roadmap: Key Take-Aways

| Order | LC P# | Difficulty | Group                | Problem Name                     | Key Points                                                                |
| ----: | ----: | :--------- | :------------------- | :------------------------------- | :------------------------------------------------------------------------ |
|     1 |   217 | Easy       | Arrays & Hashing     | Contains duplicate               |                                                                           |
|     2 |   242 | Easy       | Arrays & Hashing     | Valid anagram                    |                                                                           |
|     3 |     1 | Easy       | Arrays & Hashing     | Two sum                          |                                                                           |
|     4 |    49 | Medium     | Arrays & Hashing     | Group anagrams                   |                                                                           |
|     5 |   347 | Medium     | Arrays & Hashing     | Top K frequent elements          | QuickSort/divide and conquer -> partitioning.                             |
|     6 |   238 | Medium     | Arrays & Hashing     | Product of array except self     | Forward and reverse iteration, or recursive binomial expansion.           |
|     7 |    36 | Medium     | Arrays & Hashing     | Valid Sudoku                     | Combines iteration over 2D array with using hashmap to detect duplicates. |
|     8 |   271 | Medium     | Arrays & Hashing     | Encode and decode strings        | [LintCode#659](https://www.lintcode.com/problem/659/). Use a separator token like \n that won't be part of any string, and have a method to read up to each token. Keeping track of vec size makes it easier to insert right number of tokens. |
|     9 |   128 | Medium     | Arrays & Hashing     | Longest consecutive sequence     | Establish semantics of a seq., and use a set to keep track of elements, with O(1)-lookup. |
|    10 |    20 | Easy       | Stack                | Valid Parentheses                | Establish semantics of matching symbols, and use a stack to keep track of unmatched parens. |
|    11 |   155 | Medium     | Stack                | Min stack (in O(1))              | Use two stacks, one for values and one for keeping track of minimum values. |
|    12 |   150 | Medium     | Stack                | Evaluate Reverse Polish Notation | RPN by pushing operands onto stack, operators pop 2 operands and push the result back. |
|    13 |    22 | Medium     | Stack                | Generate parentheses             | Describe how to traverse search tree (done? go left? go right?), and then use recursive backtracking. |
|    14 |   739 | Medium     | Stack                | Daily temperatures               | Maintain a monotonically decreasing stack of <int:index, int:value>, and pop pairs with temps[i] > stack.top().value. |
|    15 |   853 | Medium     | Stack                | Car fleet                        |  |


## Other: Key Take-Aways

| Order | LC P# | Difficulty | Group                | Problem Name                 | Key Points      |
| ----: | ----: | :--------- | :------------------- | :--------------------------- | :-------------- |
|    B1 |  1480 | Easy       | LC Beginner's Guide  | Running sum                  |                 |
|    B2 |  1672 | Easy       | LC Beginner's Guide  | Richest customer wealth      |                 |
|    B3 |   412 | Easy       | LC Beginner's Guide  | Fizz Buzz                    |                 |
|    B4 |  1342 | Easy       | LC Beginner's Guide  | Number of steps              |                 |
|    B5 |   876 | Easy       | LC Beginner's Guide  | Middle of the linked list    |                 |
|    B6 |   383 | Easy       | LC Beginner's Guide  | Ransom note                  |                 |

## Generate scaffolding for solving a problem
- Run `tools/make_prob.py <number> <snake_case_name>`
