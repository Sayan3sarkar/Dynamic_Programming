import sys

t = [[-1 for j in range(1000)] for i in range(1000)]

def PP_Memoization_Optimised(s,i,j):

    rev_s = s[::-1]
    if(i >= j):
        return 0
    if(s == rev_s): # Checking if original string is boolean
        return 0
    t[i][j] = sys.maxsize
    left = 0
    right = 0
    for k in range(i,j):

        if(t[i][k] != -1): # Checking if solution of sub problem for i to k already exists in t
            left = t[i][k]
        else:
            left = PP_Memoization_Optimised(s, i, k)
            t[i][k] = left

        if(t[k+1][j] != -1): # Checking if solution of sub problem for k+1 to j already exists in t
            right = t[k+1][j]
        else:
            right = PP_Memoization_Optimised(s, k+1, j)
            t[k+1][j] = right

        t[i][j] = min(
            t[i][j],
            left + right + 1
        )
    return t[i][j]

s = "geek"
n = len(s)
print(PP_Memoization_Optimised(s, 1, n - 1))