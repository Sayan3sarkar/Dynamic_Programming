#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int Boolean_Parenthesization_Recursive(string s, int i, int j, int isTrue){
    if(i > j)
        return 0;
    if(i == j){
        if(isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    int ans = 0;
    for(int  k = i + 1; k < j; k = k + 2){
        int lT = Boolean_Parenthesization_Recursive(s, i, k - 1, 1);
        int lF = Boolean_Parenthesization_Recursive(s, i, k - 1, 0);
        int rT = Boolean_Parenthesization_Recursive(s, k + 1, j , 1);
        int rF = Boolean_Parenthesization_Recursive(s, k + 1, j , 0);
        if(s[k] == '&'){
            if(isTrue == 1)
                ans += lT*rT;
            else
                ans += lT*rF + lF*rT + lF*rF;
        }
        if(s[k] == '|'){
            if(isTrue == 1)
                ans += lT*rT + lT*rF + lF*rT;
            else
                ans += lF*rF;
        }
        if(s[k] == '^'){
            if(isTrue == 1)
                ans += lF*rT + lT*rF;
            else
                ans += lT*rT + lF*rF;
        }
    }
    return ans;
}


int main()
{
    string symbols = "TTFT";
    string operators = "|&^";
    string s;
    int j = 0;
 
    for (int i = 0; i < symbols.length(); i++)
    {
        s.push_back(symbols[i]);
        if (j < operators.length())
            s.push_back(operators[j++]);
    }
     
    // We obtain the string  T|T&F^T
    int n = s.length();
    cout << Boolean_Parenthesization_Recursive(s, 0, n-1, 1);

    return 0;
}