def unboundedKnapSackDP(wt,val,W,n):
    t = [[0 for j in range(W+1)] for i in range(n+1)] # Initialisation of matrix with 0

    # The remaining 2 loops initiate the matrix with zero at O(n). Optional since entire matrix already initialised to zero
    # for i  in range(n+1):
    #     t[i][0] = 0
    # for j in range(W+1):
    #     t[0][j] = 0

    for i in range(1, n+1):
        for j in range(1, W+1):
            t[i][j] = max(val[i-1] + t[i][j-wt[i-1]],t[i-1][j]) if (wt[i-1] <= j) else t[i-1][j]
    
    return t[n][W]

val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)
print(unboundedKnapSackDP(wt, val, W, 3))