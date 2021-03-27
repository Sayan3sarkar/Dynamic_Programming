#include <iostream>

using namespace std;

int knapsack(int wt[], int val[], int W, int n) {
    if(n == 0 || W == 0)
        return 0;
    else if(wt[n-1] <= W)
        return std::max(val[n-1] + knapsack(wt, val, W - wt[n-1], n-1),knapsack(wt, val, W, n-1));
    else //wt[n-1] > W
        return knapsack(wt, val, W, n-1);
}

int main()
{
    // cout<<"Hello World";
    int weight[] = { 10, 20, 30 };
    int val[] = { 60, 100, 120 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack(weight, val, W, n);

    return 0;
}