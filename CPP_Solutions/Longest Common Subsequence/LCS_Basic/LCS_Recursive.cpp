#include <iostream>

using namespace std;

int LCS_Recursive(char x[], char y[], int n, int m) {
    if(n==0 or m==0)
        return 0;
    else if(x[n-1] == y[m-1])
        return 1 + LCS_Recursive(x, y, n-1, m-1);
    else
        return std::max(LCS_Recursive(x, y,n, m-1),LCS_Recursive(x, y, n-1, m));
}

int main()
{
    // cout<<"Hello World";
    char x[] = "abcdgh";
    char y[] ="abedfhr";
    int n = (sizeof(x) / sizeof(x[0])) - 1; // -1 since strings end with '/0' and that adds 1 index to the char array
    int m = (sizeof(y) / sizeof(y[0])) - 1;
    cout << LCS_Recursive(x,y,n,m);

    return 0;
}