#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int coinChangeMinCoins(int coin[], int Sum, int n) {
    int t[n+1][Sum+1];

    for(int i = 0; i< n+1; i++)
        t[i][0] = 0; // Fill First column with 0
    for(int j = 1; j < Sum + 1; j++)
        t[0][j] = INT_MAX - 1; // Fill first row except first element with INT_MAX - 1(We add minus 1 because while processing we always add plus 1 and 1 + INT_MAX might lead to errors)
    for(int i = 1; i < n+1; i++)
        for(int j = 1; j < Sum + 1; j++)
            t[i][j] = (coin[i-1] <= j) ? (std::min(
                1+ t[i][j - coin[i-1]],
                t[i-1][j]
            )) : t[i-1][j];
    return ((t[n][Sum] > Sum)? -1 : t[n][Sum]);
}

int main()
{
    int coin[] = { 3, 4, 5, 8 };
    int Sum = 32;
    int n = sizeof(coin) / sizeof(coin[0]);
    cout << coinChangeMinCoins(coin, Sum, n);

    return 0;
}