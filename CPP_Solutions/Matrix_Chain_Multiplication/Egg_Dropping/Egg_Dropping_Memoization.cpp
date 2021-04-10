#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int t[1001][1001];

int eggDrop_Memoization(int e, int f)
{
    if (f == 1 || f == 0)
        return f;
    if (e == 1)
        return f;
        
    if(t[e][f] != -1)
        return t[e][f];
 
    int ans = INT_MAX, temp;
    for (int k = 1; k <= f; k++) {
        temp = 1+ std::max(
            eggDrop_Memoization(e - 1, k - 1),
            eggDrop_Memoization(e, f - k)
        );
        ans = std::min(ans, temp);
    }
 
    return t[e][f] = ans;
}

int main()
{
    memset(t, -1, sizeof(t));
    int n = 3;
    int k = 5;
    cout << eggDrop_Memoization(n , k);
    return 0;
}