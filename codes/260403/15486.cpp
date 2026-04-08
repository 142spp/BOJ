#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int,int>> v(n+1); // i번째 날에 상담에 필요한 날, 이득
    for(int i=1; i<=n; i++){
        cin >> v[i].first >> v[i].second;
    }
    vector<int> dp(n+2); // i번째 날 상담을 받앗을때 최대치
    for(int i=1; i<=n; i++){
        dp[i] = max(dp[i-1],dp[i]);
        if(i+v[i].first > n+1) continue;
        dp[i+v[i].first] = max(dp[i]+v[i].second,dp[i+v[i].first]);
    }
    cout << *max_element(dp.begin(),dp.end());
}