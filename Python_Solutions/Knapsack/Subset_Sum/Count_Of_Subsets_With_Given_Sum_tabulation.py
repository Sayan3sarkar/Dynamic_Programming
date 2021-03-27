def countOfSubsetWithGivenSum(arr, sum, n):
    t = [[0 for j in range(sum+1)] for i in range(n+1)] # initialisation of enitre matrix with zero

    # Initialise first column to true
    for i in range(n+1):
        t[i][0] = 1
    
    # Initialise first row excluding first element as zero(this loop is not necessary as already all elements 
    # of matrix exlcuding the one's in the previous loop is zero)
    # for j in range(1, sum+1):
    #     t[0][j] = 0

    # Main Iterative code
    for i in range(1, n+1):
        for j in range(1, sum+1):
            if(arr[i-1] <= j):
                t[i][j] = (t[ i - 1 ][ j - arr[ i - 1 ]]) + (t[i-1][j])
            else: # if(arr[i-1]>j)
                t[i][j] = t[i-1][j]

    return t[n][sum]

arr = [2,3,5,6,8,10]
sum = 10
n = len(arr)
print(countOfSubsetWithGivenSum(arr, sum, n))