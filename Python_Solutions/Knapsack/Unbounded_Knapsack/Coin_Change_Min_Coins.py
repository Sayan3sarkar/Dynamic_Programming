import sys

def coinChangeMinCoins(coin, Sum, n):
    t = [[(sys.maxsize - 1) for j in range(Sum + 1)] for i in range(n + 1)] # initialisation of matrix with sys.maxsize - 1
    # Fill first row except first element with INT_MAX - 1(We add minus 1 because while processing we always add plus 1 and 1 + INT_MAX might lead to errors)

    # initialisation of first column with zero
    for i  in range(n+1):
        t[i][0] = 0
    # Initialise first row excluding first element as sys.maxsize - 1(this loop is not necessary as already all elements 
    # of matrix exlcuding the one's in the previous loop is zero)
    # for j in range(1, Sum + 1):
    #     t[0][j] = sys.maxsize - 1

    for i in range(1,n+1):
        for j in range(1,Sum+1):
            t[i][j] = (min(
                1+ t[i][j - coin[i-1]],
                t[i-1][j]
            )) if (coin[i-1] <= j) else t[i-1][j]

    return (t[n][Sum] if (t[n][Sum] <= Sum) else -1)

coin = [3,4,5,8]
Sum = 32
n = len(coin)
print(coinChangeMinCoins(coin, Sum, n))