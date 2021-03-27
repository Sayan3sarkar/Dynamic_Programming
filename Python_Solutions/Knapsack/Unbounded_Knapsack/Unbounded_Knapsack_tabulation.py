def knapSackDP(wt,val,W,n):
    t = [[0 for j in range(W+1)] for i in range(n+1)] # Initialisation of matrix with 0

    for i in range(n+1):
        for j in range(W+1):
            if(i == 0 or j == 0):
                t[i][j] = 0
            elif(wt[i-1] <= j):
                t[i][j] = max(
                    val[i-1] + t[i][j-wt[i-1]],
                    t[i-1][j]
                )
            else: # if(wt[i-1] > j)
                t[i][j] = t[i-1][j]
    
    return t[n][W]

val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)
print(knapSackDP(wt, val, W, 3))