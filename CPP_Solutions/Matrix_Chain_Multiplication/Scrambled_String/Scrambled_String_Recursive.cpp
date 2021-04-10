#include <bits/stdc++.h>
#include <string.h>
using namespace std;

bool Scrambled_String_Recursive(string a, string b){
    // Base Conditions
    if(a.length()!= b.length()) // When strings are not of ame length
        return false;
        
    if(a.length() < 1 && b.length() < 1) // When both strings are empty
        return true;
        
    if(a == b) // When both strings are equal
        return true;
        
    if(a.length() < 1) // When one of the strings are empty
        return false;
        
    // Main Iterative Code
    int n = a.length();
    for(int i = 1; i< n; i++){
        bool cond1 = (
            (Scrambled_String_Recursive(a.substr( 0 , i ), b.substr(n - i , i )))
            &&
            (Scrambled_String_Recursive(a.substr( i , n - i), b.substr( 0 , n - i)))
        );
        bool cond2 = (
            (Scrambled_String_Recursive(a.substr( 0 , i ), b.substr( 0 , i )))
            &&
            (Scrambled_String_Recursive(a.substr( i , n - i), b.substr( i , n - i)))
        );
        return (cond1 || cond2);
    }
}
int main()
{
    string a = "great";
    string b = "tgare";
    cout << Scrambled_String_Recursive(a,b);
    return 0;
}