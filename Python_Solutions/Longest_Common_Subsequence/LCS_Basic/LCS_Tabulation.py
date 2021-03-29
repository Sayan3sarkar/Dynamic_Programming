def LCS_DP(x,y,n,m):
    t = [[0 for j in range(m+1)] for i in range(n+1)] # Initialise matrix with zero

    for i in range(n+1):
        for j in range(m+1):
            t[i][j] = (1 + t[i-1][j-1]) if(x[i-1] == y[j-1]) else (max(t[i-1][j], t[i][j-1]))

    return t[n][m]

x = "abcdgh"
y = "abedfhr"
print(LCS_DP(x,y,len(x), len(y)))