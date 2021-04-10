#include <bits/stdc++.h>
#include<algorithm>
#include <string.h>
using namespace std;

int t[1001][1001];

int eggDrop_Memoization_Optimised(int e, int f)
{
    if (f == 1 || f == 0)
        return f;
    if (e == 1)
        return f;
        
    if(t[e][f] != -1)
        return t[e][f];
 
    int ans = INT_MAX, temp, low, high;
    for (int k = 1; k <= f; k++) {
        
        if(t[e - 1][k - 1] != -1)
            low = t[e - 1][k - 1];
        else {
            low = eggDrop_Memoization_Optimised(e - 1, k - 1);
            t[e - 1][k - 1] = low;
        }
        
        if(t[e][f - k] != -1)
            high = t[e][f - k];
        else {
            high = eggDrop_Memoization_Optimised(e, f - k);
            t[e][f - k] = high;
        }
        
        temp = 1 + std::max(low,high);
        ans = std::min(ans, temp);
    }
 
    return t[e][f] = ans;
}

int main()
{
    // mp.clear();
    memset(t, -1, sizeof(t));
    int n = 3;
    int k = 5;
    cout << eggDrop_Memoization_Optimised(n , k);
    return 0;
}