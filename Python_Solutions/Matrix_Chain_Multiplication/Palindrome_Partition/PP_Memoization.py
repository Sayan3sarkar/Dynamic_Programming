import sys

def PP_Memoization(s,i,j):
    t = [[-1 for y in range(j+1)] for x in range(i+1)]
    rev_s = s[::-1]
    if(i >= j):
        return 0
    if(s == rev_s): # Checking if original string is boolean
        return 0
    t[i][j] = sys.maxsize
    for k in range(i,j):
        t[i][j] = min(
            t[i][j],
            PP_Memoization(s, i, k) + PP_Memoization(s, k+1, j) + 1
        )
    return t[i][j]

s = "geek"
n = len(s)
print(PP_Memoization(s, 1, n - 1))