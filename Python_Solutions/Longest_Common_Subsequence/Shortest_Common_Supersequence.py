def LCS_DP(x,y,n,m):
    t = [[0 for j in range(m+1)] for i in range(n+1)] # Initialise matrix with zero

    for i in range(1, n+1):
        for j in range(1, m+1):
            t[i][j] = (1 + t[i-1][j-1]) if(x[i-1] == y[j-1]) else (max(t[i-1][j], t[i][j-1]))

    return t[n][m]

def shortestCommonSuperSequence(x,y,n,m):
    return (n + m - LCS_DP(x,y,n,m))

x = "aggtab"
y = "gxtxayb"
n = len(x)
m = len(y)
print(shortestCommonSuperSequence(x,y,n,m))