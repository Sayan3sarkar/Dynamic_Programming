#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

// Given Constraints i & j <= 1000
int t[1001][1001];
int PP_Memoization_optimized(string s, int i, int j){
    string s_reversed = s;
    reverse(s_reversed.begin(), s_reversed.end()); // Reveresed String Obtained
    if(i>=j)
        return 0;
    if(s == s_reversed) // Check if original string is a boolean
        return  0;
    if(t[i][j] != -1)
        return t[i][j];
    t[i][j] = INT_MAX;
    int left,right;
    for(int k = i; k < j; k++){
        
        if(t[i][k] != -1) // Checking if solution of sub problem for i to k already exists in t
            left = t[i][k];
        else{
            left = PP_Memoization_optimized(s,i,k);
            t[i][k] = left;
        }
        
        if(t[k + 1][j] != -1) // Checking if solution of sub problem for k+1 to j already exists in t
            right = t[k + 1][j];
        else{
            right = PP_Memoization_optimized(s, k + 1, j);
            t[k + 1][j] = right;
        }
        t[i][j] = std::min(
            t[i][j],
            left + right + 1
        );
    }
    return t[i][j];
}

int main()
{
    memset(t,-1,sizeof(t));
    string s = "geek";
    int n = s.length();
    cout << PP_Memoization_optimized(s, 1, n-1);

    return 0;
}