#include <iostream>

using namespace std;

// Considering Constraints n<=100 and W<=1000

int knapsackDP(int wt[], int val[], int W, int n) {
    
    int t[n+1][W+1];
    
    // For initialization with time complexity of O(n), the following lines should be enough
        for(int i=0; i< n+1; i++)
            t[i][0] = 0;
            
        for (int j  = 0; j< W+1; j++)
            t[0][j] = 0;

        for(int i = 1; i< n+1; i++)
            for(int j =1; j< W+1; j++)
                t[i][j] = (wt[i-1] <= j) ? (std::max(val[i-1]  + t[i][j-wt[i-1]],  t[i-1][j])) : t[i-1][j];

    return t[n][W];
}

int main()
{
    int weight[] = { 10, 20, 30 };
    int val[] = { 60, 100, 120 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsackDP(weight, val, W, n);

    return 0;
}