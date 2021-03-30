#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std; 

string print_SCS(char x[], char y[], int n, int m){
    
    // apply LCS
    int t[n+1][m+1];
    
    for(int i = 0; i < n + 1; i++)
        t[i][0] = 0;
    for(int j = 0; j < m + 1; j++)
        t[0][j] = 0;
        
    for(int i = 1; i < n + 1; i++)
        for(int j = 1; j < m + 1; j++)
            t[i][j] = (x[i-1] == y[j-1]) ? (1 + t[i-1][j-1]) : std::max(t[i-1][j], t[i][j-1]);
    // value for t[n][m] has been obtained by applying LCS
    string scs;
    int i = n , j = m ;
    while(i > 0 && j > 0){
        if(x[i-1] == y[j-1]){
            scs.push_back(x[i-1]);
            i--;
            j--;
        }
        else if(t[i-1][j] > t[i][j-1]){
            scs.push_back(x[i-1]);
            i--;
        }
        else {
            scs.push_back(y[j-1]);
            j--;
        }
    }
    while(i > 0){ // j  has already become zero
        scs.push_back(x[i-1]);
        i--;
    }
    while(j > 0){// i has already become zero
        scs.push_back(y[j-1]);
        j--;
    }
    reverse(scs.begin(),scs.end());
    return scs;
}

int main() 
{
    char x[] = "acbcf";
    char y[] = "abcdaf";
    int n = (sizeof(x) / sizeof(x[0])) - 1;
    int m = (sizeof(y) / sizeof(y[0])) - 1;
    cout << print_SCS(x,y,n,m);
    return 0;
}