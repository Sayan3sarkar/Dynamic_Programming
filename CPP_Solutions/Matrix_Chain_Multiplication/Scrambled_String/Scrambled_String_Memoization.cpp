#include <bits/stdc++.h>
#include <string.h>
using namespace std;

unordered_map<string, int> mp;

bool Scrambled_String_Memoization(string a, string b){
    // Base Conditions
    if(a.length()!= b.length()) // When strings are not of ame length
        return false;
        
    if(a.length() < 1 && b.length() < 1) // When both strings are empty
        return true;
        
    if(a == b) // When both strings are equal
        return true;
        
    if(a.length() < 1) // When one of the strings are empty
        return false;
        
    string temp = a;
    temp.push_back(' ');
    temp.append(b); // String of format "<a> <b>" obtained
    
    if(mp.find(temp) != mp.end())
        return mp[temp];
        
    // Main Iterative Code
    int n = a.length();
    bool flag = false;
    for(int i = 1; i< n; i++){
        bool cond1 = (
            (Scrambled_String_Memoization(a.substr( 0 , i ), b.substr(n - i , i )))
            &&
            (Scrambled_String_Memoization(a.substr( i , n - i), b.substr( 0 , n - i)))
        );
        bool cond2 = (
            (Scrambled_String_Memoization(a.substr( 0 , i ), b.substr( 0 , i )))
            &&
            (Scrambled_String_Memoization(a.substr( i , n - i), b.substr( i , n - i)))
        );
        if(cond1 || cond2){
            flag = true;
            break;
        }
    }
    return mp[temp] = flag;
}
int main()
{
    mp.clear();
    string a = "great";
    string b = "tgare";
    cout << Scrambled_String_Memoization(a,b);
    return 0;
}