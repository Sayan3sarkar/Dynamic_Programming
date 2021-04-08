#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

unordered_map<string, int> mp;

int BP_Memoization(string s, int i, int j, int isTrue){
    if(i > j)
        return 0;
    if(i == j){
        if(isTrue == 1)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    
    string temp = std::to_string(i);
    temp.push_back(' ');
    temp.append(std::to_string(j));
    temp.push_back(' ');
    temp.append(std::to_string(isTrue)); // String of format '<i> <j> <isTrue>' is obtained
    
    if(mp.find(temp) != mp.end())
        return mp[temp];
    
    int ans = 0;
    for(int  k = i + 1; k < j; k = k + 2){
        int lT = BP_Memoization(s, i, k - 1, 1);
        int lF = BP_Memoization(s, i, k - 1, 0);
        int rT = BP_Memoization(s, k + 1, j , 1);
        int rF = BP_Memoization(s, k + 1, j , 0);
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
    return mp[temp] = ans;
}


int main()
{
    mp.clear();
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
    cout << BP_Memoization(s, 0, n-1, 1);

    return 0;
}