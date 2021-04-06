def print_SCS(x,y,n,m):
    t = [[0 for j in range(m+1)] for i in range(n+1)] # Initialise matrix with zero

    for i in range(1, n+1):
        for j in range(1, m+1):
            t[i][j] = (1 + t[i-1][j-1]) if(x[i-1] == y[j-1]) else (max(t[i-1][j], t[i][j-1]))

    # Value for t[n][m] obtained

    scs = ""
    i = n
    j = m
    while i > 0 and j > 0:
        if(x[i-1] == y[j-1]):
            scs += x[i-1]
            i-=1
            j-=1
        elif(t[i-1][j]>t[i][j-1]):
            scs += x[i-1]
            i-=1
        else:
            scs += y[j-1]
            j-=1
    
    while i > 0: # j has already become zero
        scs += x[i-1]
        i-=1
    while j > 0: # i has already become zero
        scs += y[j-1]
        j-=1
    scs = list(scs)
    scs.reverse()
    return "".join(scs) # since scs stores the each character as elements of an array/list

x = "acbcf"
y = "abcdaf"
print(print_SCS(x,y,len(x),len(y)))