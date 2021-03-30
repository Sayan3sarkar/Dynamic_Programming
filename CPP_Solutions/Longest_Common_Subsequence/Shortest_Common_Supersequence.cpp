#include<iostream>
#include<algorithm>
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

int shortestCommonSuperSequence(char x[], char y[], int n, int m){
    return (n + m - LCS_DP(x,y,n,m));
}

int main() 
{ 
    char x[] = "aggtab";
    char y[] ="gxtxayb";
    int n = (sizeof(x) / sizeof(x[0])) - 1;
    int m = (sizeof(y) / sizeof(y[0])) - 1;
    cout << shortestCommonSuperSequence(x,y,n,m);
    return 0;
}