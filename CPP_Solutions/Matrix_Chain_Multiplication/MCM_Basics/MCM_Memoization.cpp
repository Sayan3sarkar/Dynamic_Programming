#include <bits/stdc++.h>
using namespace std;

// constraints that i and j <= 1000
int t[1001][1001];
int MCM_Memoization(int arr[], int i, int j){
    if(i>=j)
    return 0;
    if(t[i][j] != -1)
     return t[i][j];
    t[i][j]= INT_MAX;
    for(int k = i; k < j; k++){
        t[i][j] = std::min(
                t[i][j],
                MCM_Memoization(arr, i, k) + MCM_Memoization(arr, k + 1, j) + arr[i - 1]*arr[k]*arr[j]
            );
    }
    return t[i][j];
}

int main()
{
    memset(t, -1, sizeof(t));
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MCM_Memoization(arr, 1, n-1);

    return 0;
}