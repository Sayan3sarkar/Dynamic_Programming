#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Considering Constraints n<=100 and sum<=1000


int minSubsetSumDifference(int arr[], int n){
    // Calculate Range
    int Range = 0;
    for(int i=0;i<n; i++)
        Range += arr[i];
        
    int t[n+1][Range+1];
        
    // subsetSum Code to fill t
    for(int i = 0; i< n+1; i++)
        t[i][0] = true; // Fill First column with true
    for(int j = 1; j < Range + 1; j++)
        t[0][j] = false; // Fill first row except first element with false
        
    // Main iterative code
    for(int i = 1; i< n+1 ; i++)
        // for(int j = 1; j< Range + 1; j++){ // Original subsetSum Loop
        for(int j = 1; j< (Range/2) + 1; j++) // In this case, Consrtuct matrix till Range/2 since S1 value won't be beyond it
            t[i][j] = (arr[i-1] <= j) ? ((t[i-1][j - arr[i-1]]) || (t[i-1][j])) : t[i-1][j];
        
    // Main iterative code
    int minDiff = INT_MAX;
    for(int j = Range/2; j >= 0; j--){ // Loop through half of Range since S1<= Range/2.
        if(t[n][j]){ // Checking each element of last row to be true. First true value at index j is S1 
            minDiff = Range - 2*j;
            break;
        }
    }
    return minDiff;
}

int main()
{
    int arr[] = { 7,1,2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minSubsetSumDifference(arr, n);

    return 0;
}