#include <bits/stdc++.h>
using namespace std;

int MCM_Recursive(int arr[], int i, int j){
    if(i>=j)
    return 0;
    int min=INT_MAX,count;
    for(int k = i; k < j; k++){
        count = MCM_Recursive(arr, i, k) + MCM_Recursive(arr, k + 1, j) + arr[i - 1]*arr[k]*arr[j];
        if(count < min)
            min = count;
    }
    return min;
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << MCM_Recursive(arr, 1, n-1);

    return 0;
}