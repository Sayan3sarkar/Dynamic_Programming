#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

// Given Constraints i & j <= 1000
int t[1001][1001];
int PP_Memoization(string s, int i, int j){
    string s_reversed = s;
    reverse(s_reversed.begin(), s_reversed.end()); // Reveresed String Obtained
    if(i>=j)
        return 0;
    if(s == s_reversed) // Check if original string is a boolean
        return  0;
    if(t[i][j] != -1)
        return t[i][j];
    t[i][j] = INT_MAX;
    for(int k = i; k < j; k++)
        t[i][j] = std::min(
            t[i][j],
            PP_Memoization(s, i, k) + PP_Memoization(s, k + 1, j) + 1
        );
    return t[i][j];
}

int main()
{
    memset(t,-1,sizeof(t));
    string s = "geek";
    int n = s.length();
    cout << PP_Memoization(s, 1, n-1);

    return 0;
}