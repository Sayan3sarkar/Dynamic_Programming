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

int countOfSubsetWithGivenDifference(int arr[], int diff, int n){
    int Range = 0;
    for(int i=0;i<n;i++)
        Range += arr[i];
    int s1 = (Range + diff)/2;
    return countOfSubsetWithGivenSum(arr, s1, n);
}

int main()
{
    int arr[] = { 1,1,2,3 };
    int diff = 1;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countOfSubsetWithGivenDifference(arr, diff, n);

    return 0;
}