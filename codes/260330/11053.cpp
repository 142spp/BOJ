#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    vector<vector<int>> dp(n,vector<int>(n));
    vector<vector<int>> maxval(n,vector<int>(n));
    for(int i=0; i<n; i++) {
        dp[i][i] = 1;
        maxval[i][i] = v[i];
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(v[j]>maxval[i][j-1]){
                maxval[i][j] = v[j];
                dp[i][j] = dp[i][j-1] + 1;
            } else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    cout << dp[0][n-1];
}



/*
O(n^2 log n) 
5 6 7 1 2 3 4
1 2 3 3 3 3 4

*/