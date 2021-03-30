#include <iostream>
#include <cstring>

using namespace std;

// Considering Constraints n,m<=1000
int t[1002][1002];

int LCS_Memoization(char x[], char y[], int n, int m) {
    if(n==0 or m==0)
        return 0;
    else if(t[n][m] != -1)
        return t[n][m];
    else if(x[n-1] == y[m-1])
        t[n][m] = 1 + LCS_Memoization(x, y, n-1, m-1);
    else
        t[n][m] = std::max(LCS_Memoization(x, y,n, m-1),LCS_Memoization(x, y, n-1, m));
        
    return t[n][m];
}

int main()
{
    memset(t, -1, sizeof(t));
    char x[] = "abcdgh";
    char y[] ="abedfhr";
    int n = (sizeof(x) / sizeof(x[0])) - 1;
    int m = (sizeof(y) / sizeof(y[0])) - 1;
    cout << LCS_Memoization(x,y,n,m);

    return 0;
}