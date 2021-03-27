#include <iostream>
#include <cstring>

using namespace std;

// Considering Constraints n<=100 and W<=1000

int t[102][1002];

int knapsackDP(int wt[], int val[], int W, int n) {
    if(n == 0 || W == 0) // Base Condition
        return 0;
    else if (t[n][W] != -1) // If any value apart from -1 is present at the last(upper limit) position
        return t[n][W];
    else if(wt[n-1] <= W){
        return t[n][W] = std::max(val[n-1] + knapsackDP(wt, val, W - wt[n-1], n-1),knapsackDP(wt, val, W, n-1));
    }
    else { //wt[n-1] > W
        return t[n][W] = knapsackDP(wt, val, W, n-1);
    }
}

int main()
{
    // cout<<"Hello World";
    memset(t, -1, sizeof(t));
    int weight[] = { 10, 20, 30 };
    int val[] = { 60, 100, 120 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsackDP(weight, val, W, n);

    return 0;
}