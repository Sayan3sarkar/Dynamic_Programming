import sys
def eggDrop_Memoization(e,f):
    t = [[-1 for j in range(f+1)] for i in range(e+1)]
    if(f == 0 or f == 1):
        return f
    if( e == 1):
        return f
    ans = sys.maxsize

    if(t[e][f] != -1):
        return t[e][f]
    for k in range(1, f+1):
        ans = min(ans, 1 + max(
            eggDrop_Memoization(e - 1, k - 1),
            eggDrop_Memoization(e, f - k)
        ))
    t[e][f] = ans
    return t[e][f]

n = 3
f = 5
print(eggDrop_Memoization(3,5))