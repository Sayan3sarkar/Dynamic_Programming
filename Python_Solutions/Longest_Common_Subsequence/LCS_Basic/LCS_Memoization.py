def LCS_Memoization(x,y,n,m):
    t = [[-1 for j in range(m+1)] for i in range(n+1)] # Initialise matrix with -1

    if(n==0 or m==0):
        return 0
    elif(t[n][m] != -1):
        return t[n][m]
    elif(x[n-1] == y[m-1]):
        t[n][m] = 1 + LCS_Memoization(x, y, n-1, m-1)
    else:
        t[n][m] = max(LCS_Memoization(x, y,n, m-1),LCS_Memoization(x, y, n-1, m))
        
    return t[n][m]

x = "abcdgh"
y = "abedfhr"
print(LCS_Memoization(x,y,len(x), len(y)))