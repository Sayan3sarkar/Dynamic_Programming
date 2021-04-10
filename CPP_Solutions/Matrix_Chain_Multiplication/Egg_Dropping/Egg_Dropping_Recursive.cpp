#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int eggDrop(int e, int f)
{
    if (f == 1 || f == 0)
        return f;
    if (e == 1)
        return f;
 
    int ans = INT_MAX, temp;
    for (int k = 1; k <= f; k++) {
        temp = std::max(
            eggDrop(e - 1, k - 1),
            eggDrop(e, f - k)
        );
        ans = std::min(ans, temp);
    }
 
    return ans + 1;
}

int main()
{
    int n = 3;
    int k = 5;
    cout << eggDrop(n , k);
    return 0;
}