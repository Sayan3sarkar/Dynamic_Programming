# Given constraints W<= 1002 and n<=102
def isSubsetSum(arr, sum, n):
    t = [[False for j in range(sum+1)] for i in range(n+1)] # initialisation of enitre matrix with false

    # Initialise first column to true
    for i in range(n+1):
        t[i][0] = True
    
    # Initialise first row excluding first element as false
    for j in range(1, sum+1):
        t[0][j] = False

    # Main Iterative code
    for i in range(1, n+1):
        for j in range(1, sum+1):
            t[i][j] = ((t[ i - 1 ][ j - arr[ i - 1 ]]) or (t[i-1][j])) if (arr[i-1] <= j) else t[i-1][j]

    return t[n][sum]

def isEqualPartition(arr, n):
    Sum = sum(arr)
    if(Sum % 2 != 0):
        return False
    else:
        return isSubsetSum(arr, Sum//2, n)

arr = [1,5,11,5]
n = len(arr)
print(isEqualPartition(arr, n))