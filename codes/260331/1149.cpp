#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    // 0 : R, 1 : G, 2 : B
    vector<vector<int>> dp(n,vector<int>(3));
    for(int i=0; i<n; i++){
        cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
    }
    for(int i=1; i<n; i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + dp[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + dp[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + dp[i][2];
    }
    int ans = INT_MAX;
    for(auto x : dp[n-1]) ans = min(ans,x);
    cout << ans;
}
