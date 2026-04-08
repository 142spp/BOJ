#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> v(2,vector<int>(n));
        for(auto& l : v){
            for(auto& x : l) cin >> x; 
        }
        // 0 : 1번째 고른거, 1 : 두번째 고른거, 2: 안고른거
        vector<vector<int>> dp(3,vector<int>(n,0));
        for(int i=0; i<2; i++) dp[i][0] = v[i][0];
        for(int i=1; i<n; i++){
            dp[0][i] = max(dp[1][i-1],dp[2][i-1])+v[0][i];
            dp[1][i] = max(dp[0][i-1],dp[2][i-1])+v[1][i];
            dp[2][i] = max({dp[0][i-1],dp[1][i-1],dp[2][i-1]});
        }
        int ans = max({dp[0][n-1],dp[1][n-1],dp[2][n-1]});
        cout << ans << "\n";
    }
}