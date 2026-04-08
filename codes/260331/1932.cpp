#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> dp[i][j];
        }
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j==0) dp[i][j] = dp[i-1][j] + dp[i][j];
            else if(j==i) dp[i][j] = dp[i-1][j-1] + dp[i][j];
            else{
                dp[i][j] += max(dp[i-1][j-1],dp[i-1][j]);
            }
        }
    }
    int ans = 0;
    for(int j=0; j<n; j++) ans = max(ans,dp[n-1][j]);
    cout << ans;
}