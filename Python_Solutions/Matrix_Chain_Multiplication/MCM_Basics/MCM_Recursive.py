import sys

def MCM_Recursive(arr, i, j):
    if(i>=j):
        return 0
    min = sys.maxsize

    for k in range(i,j):
        count = MCM_Recursive(arr, i, k) + MCM_Recursive(arr, k+1, j) + arr[i-1]*arr[k]*arr[j]
        if count < min:
            min = count

    return min

arr = [40,20,30,10,30]
n = len(arr)
print(MCM_Recursive(arr, 1, n-1))