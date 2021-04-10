import sys
def eggDrop(e,f):
    if(f == 0 or f == 1):
        return f
    if( e == 1):
        return f
    ans = sys.maxsize

    for k in range(1, f+1):
        ans = min(ans, max(
            eggDrop(e - 1, k - 1),
            eggDrop(e, f - k)
        ))
    return ans + 1

n = 3
f = 5
print(eggDrop(3,5))