#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

int PP_Recursive(string s, int i, int j){
    string s_reversed = s;
    reverse(s_reversed.begin(), s_reversed.end()); // Reveresed String Obtained
    if(i>=j)
        return 0;
    if(s == s_reversed) // Check if original string is a boolean
        return  0;
    int min = INT_MAX, temp;
    for(int k = i; k < j; k++){
        temp = PP_Recursive(s, i, k) + PP_Recursive(s, k + 1, j) + 1; // We add this one since original string has 
        // already been partitioned to solve the subproblems. So that initial partition counts as 1
        if(temp<min)
            min = temp;
    }
    return min;
}

int main()
{
    string s = "geek";
    int n = s.length();
    cout << PP_Recursive(s, 1, n-1);

    return 0;
}