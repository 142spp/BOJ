#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<vector<long long>> dp(n+1,vector<long long>(10));
    for(int j=0; j<10; j++) dp[1][j] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<10;j++){
            for(int k=0;k<=j;k++){
                dp[i][j] = (dp[i][j]+dp[i-1][k])%10007;
            }
        }
    }   
    long long ans = 0;
    for(auto x : dp[n]) ans = (ans+x)%10007;
    cout << ans%10007;
}

/*
dp[i][j] = j로 끝나는 i 자릿수의 개수
dp[i][j] = dp[i-1][0~j]

*/