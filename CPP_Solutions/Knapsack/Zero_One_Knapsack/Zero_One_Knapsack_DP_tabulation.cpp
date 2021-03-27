#include <iostream>
// #include <cstring>

using namespace std;

// Considering Constraints n<=100 and W<=1000

int t[102][1002]; // auto initialization to zero

int knapsackDP(int wt[], int val[], int W, int n) {
    
    // Initialization. For C/C++, this step is optional because simple declaration of a 2d matrix without initialization fills it with zero by default. So
    // time complexity for initialization becomes O(1) for initialization
    
        // For initialization with time complexity of O(n*W) the following loop should be enough
        
        // for(int i = 0; i < n+1; i++)
        //     for(int j = 0; j< W+1; j++)
        //         t[i][j] = 0;
    
        // For initialization with time complexity of O(n), the following lines should be enough
            // for(int i=0; i< n+1; i++)
            //     t[i][0] = 0;
                
            // for (int j  = 0; j< W+1; j++)
            //     t[0][j] = 0;
        
        for(int i = 1; i< n+1; i++){
            for(int j = 1; j< W+1; j++){
                // if(i == 0 || j == 0)
                //     t[i][j] = 0;
                /*else*/ 
                if(wt[i-1] <= j){
                    t[i][j] = std::max(val[i-1]  + t[i-1][j-wt[i-1]],  t[i-1][j]) ;
                } else { // if wt[i-1] > W
                    t[i][j] = t[i-1][j];
                }
            }
        }
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
