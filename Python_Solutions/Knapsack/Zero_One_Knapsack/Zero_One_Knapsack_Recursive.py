def knapSack( wt, val, W, n):
    if (n == 0 or W == 0):
        return 0
    elif (wt[n-1] <= W):
        return max(
            val[n-1] + knapSack( wt, val, W-wt[n-1], n-1),
            knapSack( wt, val, W, n-1))        
    else:
        return knapSack(W, wt, val, n-1)

val = [60, 100, 120]
wt = [10, 20, 30]
W = 50
n = len(val)
print(knapSack(wt, val, W, 3))