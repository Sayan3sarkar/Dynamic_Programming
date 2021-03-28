#include <iostream>
// #include <cstring>

using namespace std;

// Considering Constraints n<=100 and sum<=1000

bool isSubsetSum(int arr[], int sum, int n){
    int t[n+1][sum+1];
    // Initialisation
    for(int i = 0; i< n+1; i++)
        t[i][0] = true; // Fill First column with true
    for(int j = 1; j < sum + 1; j++)
        t[0][j] = false; // Fill first row except first element with false
        
    // Main iterative code
    for(int i = 1; i< n+1 ; i++)
        for(int j = 1; j< sum + 1; j++)
            t[i][j] = (arr[i-1] <= j) ? ((t[i-1][j - arr[i-1]]) || (t[i-1][j])) : t[i-1][j];
            
    return t[n][sum];
}

int main()
{
    int arr[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << isSubsetSum(arr, sum, n);

    return 0;
}