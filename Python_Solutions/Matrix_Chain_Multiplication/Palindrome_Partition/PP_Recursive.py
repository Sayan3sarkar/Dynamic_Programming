import sys

def PP_Recursive(s,i,j):
    rev_s = s[::-1]
    if(i >= j):
        return 0
    if(s == rev_s): # Checking if original string is boolean
        return 0
    minPartition = sys.maxsize
    for k in range(i,j):
        temp = PP_Recursive(s, i, k) + PP_Recursive(s, k+1, j) + 1 # We add this one since original string has already
        # been partitioned to solve the subproblems. So that initial partition counts as 1
        if(temp < minPartition):
            minPartition = temp
    return minPartition

s = "geek"
n = len(s)
print(PP_Recursive(s, 1, n - 1))