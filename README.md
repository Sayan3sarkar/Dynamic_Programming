# Dynamic Programming

According to educative.io,

> Dynamic Programming (DP) is an algorithmic technique for solving an optimization problem by breaking it down into simpler subproblems and utilizing the fact that the optimal solution to the overall problem depends upon the optimal solution to its subproblems.

## Problems solved here using both C++ and Python

1. **Knapsack**
    * **0/1 Knapsack**
        * Recursive
        * Memoization(Top-Down approach)
        * Tabulation(Bottom-Up approach)
    * **Subset Sum**(all using Tabulation)(variations of 0/1 Knapsack)
        * Is Subset Sum
        * Equal Partition Sum
        * Count of Subsets with given sum
        * Minimum Subset Sum Difference
        * Count of Subsets with given difference(another variation of exact same problem is Target Sum)
    * **Unbounded Knapsack**
        * Rod Cutting(Literally Unbounded knapsack but with another name)
        * Coin Change: Max number of ways(Unbounded knapsack version of ***Count of Subsets with given sum*** problem)
        * Coin change: Min number of coins

2. **Longest Common Subsequence(LCS)**
    * **LCS** at it's very basic form
        * Recursive
        * Memoization(Top-Down approach)
        * Tabulation(Bottom-Up approach)
    * **Longest Common Substring**
    * **Shortest Common SuperSequence(SCS)**
    * **Print SCS**
    * **Print LCS**
    * **Minimum number of insertion and deletion to convert one string to another**
    * **Longest Repeating Subsequence(LRS)**
    * **Palindromic Subsequence** problems:
        * Longest Palindromic Subsequence(LPS)
        * Min number of deletions(same result for minimum insertions) for a string to become a palindrome(Ans: len(string) - result of LPS)
    * **Sequence Matching Pattern**

3. **Matrix Chain Multiplication(MCM)**
    * **MCM** basics
        * Recursive
        * Memoization(Top-Down approach)
    * **Palindrome Partitioning(Recursive and Memoization)**
    * **Evaluate Expression to True(Boolean Partitioning)**
    * **Scrambled String**
    * **Egg Dropping**