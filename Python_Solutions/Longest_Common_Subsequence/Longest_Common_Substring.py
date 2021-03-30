def LCSubstr_Tabulation(x,y,n,m):
    t = [[0 for j in range(m+1)] for i in range(n+1)] # Initialise matrix with zero
    result = 0

    for i in range(1, n+1):
        for j in range(1, m+1):
            if (x[i-1] == y[j-1]):
                t[i][j] = 1 + t[i-1][j-1]
                result = max(result, t[i][j])
            else:
                t[i][j] = 0
    return result

x = "abcdgh"
y = "abedfhr"
print(LCSubstr_Tabulation(x,y,len(x),len(y)))