def Scrambled_String_Recursive(a,b):
    # Base Conditions    
    if (len(a) != len(b)): # When strings are not of ame length
        return False

    if(len(a) == 0 and len(b) == 0): # When both strings are empty
        return True
    
    if(a == b): # When both strings are equal
        return True

    if(len(a) < 1): # Only 1 string is empty
        return False

    # n = len(a)
    for i in range(1,n):
        cond1 = (Scrambled_String_Recursive(a[:i], b[-i:])) and (Scrambled_String_Recursive(a[i:], b[:-i]))
        cond2 = (Scrambled_String_Recursive(a[:i], b[:i])) and (Scrambled_String_Recursive(a[i:], b[i:]))
        if(cond1 or cond2):
            return True
    return False

a = "great"
b = "tgare"
print(Scrambled_String_Recursive(a,b))