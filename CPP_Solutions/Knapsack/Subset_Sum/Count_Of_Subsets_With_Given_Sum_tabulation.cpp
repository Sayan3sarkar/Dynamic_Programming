#include <iostream>

using namespace std;

// Considering Constraints n<=100 and sum<=1000
// int t[102][1002];

int countOfSubsetWithGivenSum(int arr[], int sum, int n){
    int t[n+1][sum+1];
    // Initialisation
    for(int i = 0; i< n+1; i++)
        t[i][0] = 1; // Fill First column with true
    for(int j = 1; j < sum + 1; j++)
        t[0][j] = 0; // Fill first row except first element with false
        
    // Main iterative code
    for(int i = 1; i< n+1 ; i++){
        for(int j = 1; j< sum + 1; j++){
            
            if(arr[i-1] <= j)
                t[i][j] = t[i-1][j] + t[i-1][j - arr[i-1]];
            else // arr[i-1] > j
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][sum];
}

int main()
{
    int arr[] = { 2,3,5,6,8,10 };
    int sum = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countOfSubsetWithGivenSum(arr, sum, n);

    return 0;
}