#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<int> wine(n+1);
    vector<vector<int>> dp(n+1,vector<int>(2)); // i 번째를 마셨을때의 최대
    for(int i=1; i<n+1; i++) {
        cin >> wine[i];
    }
    dp[1][0] = wine[1];
    int ans = wine[1];
    if(n>=2){
        dp[2][0] = wine[2];
        dp[2][1] = wine[1]+wine[2];
        ans = dp[2][1];
    }

    for(int i=3; i<n+1; i++){
        dp[i][0] = max({dp[i-3][0],dp[i-3][1],dp[i-2][0],dp[i-2][1]}) + wine[i];// i번째 마시는데 얘가 처음
        dp[i][1] = dp[i-1][0] +wine[i];// i번째 마시는데 얘가 두번째
        ans = max(max(dp[i][0],dp[i][1]),ans);
    }
    cout << ans;
}

/*
xxo
xoo
oxo

oox
oxx
xox
*/