# Notes on DP

* Longest Common Subsequence(LCS)
    *   Shortest Common Supersequence(SCS): count = (len(s1)+len(s2) - LCS(a,b))
    *   Min number of insertion and deletion to convert string s1 to s2 
        *   insertion: len(s1) - LCS(s1,s2)
        *   deletion: len(s2) - LCS(s1,s2)
    *   Longest Palindromic Subsequence(LPS): count = LCS(s1, reverse_of_s1)
    *   Min deletion in a string to make it a palindrome: len(s1) - LPS(s1)
    *   Min insertion in a string to make it a palindrome: len(s1) - LPS(s1) {Same as min deletion}
    *   Largest Repeating Subsequence(LRS): count = (LCS(s1,s1) but with condition that i!=j)
    *   Sequence Matching Pattern(Find if s1 is subsequence of s2): if(length of LCS(s1,s2) == len(s1))

* Matrix Chain Multiplication(MCM)