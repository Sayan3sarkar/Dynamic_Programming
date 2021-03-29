#include <iostream>
#include <cstring>

using namespace std;

// Considering Constraints n,m<=1000

int LCSubStr(char x[], char y[], int n, int m)
{
    int t[m + 1][n + 1];
    int result = 0; 
    
    for (int i = 0; i < n+1; i++)
        t[i][0] = 0;
        
    for  (int j = 0; j < m+1; j++)
        t[0][j] = 0;
    for (int i = 1; i < n+1; i++){
       for  (int j = 1; j < m+1; j++){
            if (x[i - 1] == y[j - 1]) {
                t[i][j] = t[i - 1][j - 1] + 1;
                result = max(result, t[i][j]);
            }
            else
                t[i][j] = 0;
        }
    }
    return result;
}

int main()
{
    char x[] = "abcde";
    char y[] ="abfce";
    int n = (sizeof(x) / sizeof(x[0])) - 1;
    int m = (sizeof(y) / sizeof(y[0])) - 1;
    cout << LCSubStr(x,y,n,m);

    return 0;
}