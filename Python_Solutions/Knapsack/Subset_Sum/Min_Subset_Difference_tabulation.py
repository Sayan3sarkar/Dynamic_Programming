# Given constraints W<= 1002 and n<=102
import sys

def minSubsetSumDifference(arr, n):
    Range = sum(arr)
    t = [[False for j in range(Range + 1)] for i in range(n+1)] # initialisation of enitre matrix with false

    # subsetSum code to fill t
    # Initialise first column to true
    for i in range(n+1):
        t[i][0] = True
    
    # Initialise first row excluding first element as False(this loop is not necessary as already all elements 
    # of matrix exlcuding the one's in the previous loop is False)
    # for j in range(1, Range+1):
    #     t[0][j] = False

    for i in range(1,n+1):
        # for j in range(1,Range + 1): # Original subsetSum Loop
        for j in range(1,(Range//2) + 1): # In this case, Consrtuct matrix till Range/2 since S1 value won't be beyond it
            t[i][j] = ((t[ i - 1 ][ j - arr[ i - 1 ]]) or (t[i-1][j])) if (arr[i-1] <= j) else t[i-1][j]

    # Main iterative code
    minDiff = sys.maxsize # Equivalent to INT_MAX in C/C++
    for j in range(Range //2, -1, -1): # Loop through half of Range since S1<= Range/2.
        if(t[n][j]): # Checking each element of last row to be true. First true value at index j is S1
            minDiff = Range - 2*j
            break

    return minDiff



arr = [7, 1, 2]
n = len(arr)
print(minSubsetSumDifference(arr, n))
    