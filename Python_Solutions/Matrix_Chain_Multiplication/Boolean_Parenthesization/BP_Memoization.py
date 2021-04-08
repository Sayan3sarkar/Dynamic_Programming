Dict = {}
def Boolean_Parenthesization_Recursive(s,i,j,isTrue):
    if(i>j):
        return False
    if(i==j):
        if(isTrue == 1):
            return s[i] == 'T'
        else:
            return s[i] == 'F'

    temp = str(i)
    temp += ' '
    temp += str(j)
    temp += ' '
    temp += str(isTrue)
    if(Dict.get(temp) != None):
        return Dict[temp]
    ans = 0
    for k in range(i + 1, j, 2) :
        lT = Boolean_Parenthesization_Recursive(s, i, k - 1, True)
        lF = Boolean_Parenthesization_Recursive(s, i, k - 1, False)
        rT = Boolean_Parenthesization_Recursive(s, k + 1, j , True)
        rF = Boolean_Parenthesization_Recursive(s, k + 1, j , False)

        if(s[k] == '&'):
            if(isTrue):
                ans += lT*rT
            else:
                ans += lT*rF + lF*rT + lF*rF
        
        if(s[k] == '|'):
            if(isTrue):
                ans += lT*rT + lF*rT + lT*rF
            else:
                ans+= lF*rF

        if(s[k] == '^'):
            if(isTrue):
                ans+= lT*rF + lF*rT
            else:
                ans += lF*rF + lT*rT

    Dict[temp] = ans
    return Dict[temp]

Dict.clear()
symbols = "TTFT"
operators = "|&^"
s = ""
j = 0
for i in range(len(symbols)) :
 
  s += symbols[i]
  if (j < len(operators)) :
    s = s + operators[j]
    j += 1
 
# We obtain the string  T|T&F^T
n = len(s)
print(Boolean_Parenthesization_Recursive(s,0,n-1,True))