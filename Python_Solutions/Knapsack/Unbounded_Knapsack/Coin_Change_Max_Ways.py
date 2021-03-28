def coinChangeMaxWays(coin, Sum, n):
    t = [[0 for j in range(Sum + 1)] for i in range(n + 1)] # initialisation of enitre matrix with zero

     # Initialise first column to true
    for i  in range(n+1):
        t[i][0] = 1

    # Initialise first row excluding first element as zero(this loop is not necessary as already all elements 
    # of matrix exlcuding the one's in the previous loop is zero)
    # for j in range(1, sum+1):
    #     t[0][j] = 0

    # Main Iterative code
    for i in range(1,n+1):
        for j in range(1, Sum+1):
            if(coin[i-1] <= j):
                t[i][j] = (t[i][ j - coin[ i - 1 ]]) + (t[i-1][j])
            else:
                t[i][j] = t[i-1][j]

    return t[n][Sum]

coin = [1,2,3]
Sum = 6
n = len(coin)
print(coinChangeMaxWays(coin, Sum, n))