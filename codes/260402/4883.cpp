#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t=1;
    while(true){
        int n; cin >> n;
        if(n==0) break;
        vector<vector<int>> dp(n,vector<int>(3));
        vector<vector<int>> cost(n,vector<int>(3));
        for(auto& c: cost){
            for(auto& x: c) cin >> x;
        }
        dp[0][1] = cost[0][1];
        dp[0][0] = 1e9;
        dp[0][2] = cost[0][1]+cost[0][2];
        for(int i=1; i<n; i++){
            dp[i][0] = min({dp[i-1][0],dp[i-1][1]}) + cost[i][0];
            dp[i][1] = min({dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i][0]}) + cost[i][1];
            dp[i][2] = min({dp[i-1][1],dp[i-1][2],dp[i][1]}) + cost[i][2];
        }
        int answer = dp[n-1][1];
        cout << t++ << ". " << answer << "\n";
    }

}