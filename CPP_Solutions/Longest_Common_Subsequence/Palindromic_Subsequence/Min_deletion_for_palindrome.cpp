#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std; 

int LCS_DP(char x[], char y[], int n, int m) {
    int t[n+1][m+1];
    
    for(int i = 0; i < n + 1; i++)
        t[i][0] = 0;
    for(int j = 0; j < m + 1; j++)
        t[0][j] = 0;
        
    for(int i = 1; i < n + 1; i++)
        for(int j = 1; j < m + 1; j++)
            t[i][j] = (x[i-1] == y[j-1]) ? (1 + t[i-1][j-1]) : std::max(t[i-1][j], t[i][j-1]);
        
    return t[n][m];
}

int LPS_DP(string x, int n){
    string x_origin = x;
    reverse(x.begin(), x.end());
    char s1[n+1], s2[n+1];
    strcpy(s1, x_origin.c_str());
    strcpy(s2, x.c_str());
    
    return LCS_DP(s1, s2, n, n);
}

int main() 
{
    string x = "agbcba";
    int n = x.length();
    cout << "Min deletion: "<< n -LPS_DP(x,n);
    return 0;
}
// Min number of insertion to make a string palindrome is also the same code