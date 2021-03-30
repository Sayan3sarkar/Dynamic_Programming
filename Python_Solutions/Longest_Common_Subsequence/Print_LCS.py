def printLCS(x,y,n,m):
    t = [[0 for j in range(m+1)] for i in range(n+1)] # Initialise matrix with zero

    for i in range(1, n+1):
        for j in range(1, m+1):
            t[i][j] = (1 + t[i-1][j-1]) if(x[i-1] == y[j-1]) else (max(t[i-1][j], t[i][j-1]))

    index = t[n][m]
    lcs = [""] * (index) #creating a character array of length index
    i=n
    j=m
    while i > 0 and j > 0:
        if(x[i-1] == y[j-1]):
            lcs[index - 1] = x[i-1]
            i-=1
            j-=1
            index-=1
        elif(t[i-1][j] > t[i][j-1]):
            i-=1
        else:
            j-=1
    return "".join(lcs) # since lcs stores the each character as elements of an array/list

x = "abcdgh"
y = "abedfhr"
print(printLCS(x,y,len(x), len(y)))