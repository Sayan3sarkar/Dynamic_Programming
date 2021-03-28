#include <iostream>

using namespace std;

// Considering Constraints n<=100 and W<=1000

int coinChangeMaxWays(int coin[], int Sum, int n) {
    
    int t[n+1][Sum+1];
    
    for(int i = 0; i< n+1; i++)
        t[i][0] = 1; // Fill First column with true
    for(int j = 1; j < Sum + 1; j++)
        t[0][j] = 0; // Fill first row except first element with false
        
    // Main iterative code
    for(int i = 1; i< n+1 ; i++){
        for(int j = 1; j< Sum + 1; j++){
            
            if(coin[i-1] <= j)
                t[i][j] = t[i-1][j] + t[i][j - coin[i-1]];
            else // arr[i-1] > j
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][Sum];
    
}

int main()
{
    int coin[] = { 1,2,3 };
    int Sum = 5;
    int n = sizeof(coin) / sizeof(coin[0]);
    cout << coinChangeMaxWays(coin, Sum, n);

    return 0;
}