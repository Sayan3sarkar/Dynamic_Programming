import sys
t = [[-1 for j in range(1001)] for i in range(1001)] #Given constraints  i & j <=1000
def MCM_Memoization(arr, i, j):
    if(i>=j):
        return 0
    if(t[i][j] != -1):
        return t[i][j]
    t[i][j] = sys.maxsize
    for k in range(i,j):
        t[i][j] = min(
            t[i][j],
            MCM_Memoization(arr, i, k) + MCM_Memoization(arr, k+1, j) + arr[i-1]*arr[k]*arr[j]
        )
    return t[i][j]

arr = [40,20,30,10,30]
n = len(arr)
print(MCM_Memoization(arr, 1, n-1))