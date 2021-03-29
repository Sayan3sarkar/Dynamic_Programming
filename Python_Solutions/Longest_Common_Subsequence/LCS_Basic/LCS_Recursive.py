def LCS_Recursive(x,y,n,m):
    if(n==0 or m==0):
        return 0
    elif (x[n-1] == y[m-1]):
        return 1 + LCS_Recursive(x,y,n-1,m-1)
    else:
        return max(
            LCS_Recursive(x,y,n,m-1),
            LCS_Recursive(x,y,n-1,m)
        )

x = "abcdgh"
y = "abedfhr"
print(LCS_Recursive(x,y,len(x), len(y)))