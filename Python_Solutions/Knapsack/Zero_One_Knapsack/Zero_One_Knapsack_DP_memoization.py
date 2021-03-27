# Given constraints W<= 1002 and n<=102
t = [[-1 for i in range(102)] for j in range(1002)]
def knapSackDP( wt, val, W, n):
    if (n==0 or W ==0):
        return 0
    elif (t[n][W] != -1):
        return t[n][W]
    elif (wt[n-1]<=W):
        t[n][W] = max(
            val[n-1] + knapSackDP(wt,val,W-wt[n-1],n-1),
            knapSackDP(wt,val,W,n-1)
        )
    else:
        t[n][W] = knapSackDP(wt,val,W,n-1)
    return t[n][W]

val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)
print(knapSackDP(wt, val, W, 3))