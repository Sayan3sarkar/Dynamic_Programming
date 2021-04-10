Dict = {}

def Scrambled_String_Memoization(a,b):
    # Base Conditions    
    if (len(a) != len(b)): # When strings are not of ame length
        return False

    if(len(a) == 0 and len(b) == 0): # When both strings are empty
        return True
    
    if(a == b): # When both strings are equal
        return True

    if(len(a) < 1): # Only 1 string is empty
        return False

    temp = a
    temp += ' '
    temp += b # String of format "<a> <b>" obtained
    
    if(Dict.get(temp) != None):
        return Dict[temp]

    # n = len(a)
    flag = False
    for i in range(1,n):
        cond1 = (Scrambled_String_Memoization(a[:i], b[-i:])) and (Scrambled_String_Memoization(a[i:], b[:-i]))
        cond2 = (Scrambled_String_Memoization(a[:i], b[:i])) and (Scrambled_String_Memoization(a[i:], b[i:]))
        if(cond1 or cond2):
            flag = True
    Dict[temp] = flag
    return Dict[temp]

a = "abbbcbaaccacaacc"
b = "acaaaccabcabcbcb"
print(Scrambled_String_Memoization(a,b))