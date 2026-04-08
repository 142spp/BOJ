#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<vector<int>> v(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> v[i][j];
        }
    }
    vector<vector<vector<int>>> dp(n,\
        vector<vector<int>>(n,vector<int>(3)));
        // 0 : 가로 1: 세로 2 : 대각
    dp[0][1][0] = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j<n-1){
                if(v[i][j+1]!=1){
                dp[i][j+1][0] += dp[i][j][0];    
                dp[i][j+1][0] += dp[i][j][2];    
            }}
            if(i<n-1){
                if(v[i+1][j]!=1){
                dp[i+1][j][1] += dp[i][j][1];
                dp[i+1][j][1] += dp[i][j][2];
            }}               
            if(j<n-1 && i<n-1){
                if(v[i+1][j+1]!=1 && v[i+1][j]!=1 && v[i][j+1]!=1){
                dp[i+1][j+1][2] += dp[i][j][0];             
                dp[i+1][j+1][2] += dp[i][j][1];             
                dp[i+1][j+1][2] += dp[i][j][2];             
            }}
        }
    }

    int ans = 0;
    for(int i=0; i<3; i++){
        ans += dp[n-1][n-1][i];
    }
    cout << ans;
}