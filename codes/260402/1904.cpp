#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<int> dp(n+1);
    dp[1] = 1; 
    if(n>=2)dp[2] = 2;
    for(int i=3; i<=n;i++){
        dp[i] = (dp[i-2]+dp[i-1])%15746;
    }
    cout << dp[n];
}

/*
1
11 00
111 100 001
1111 1100 1001 0011 0000
11111 11100 11001 10011 00111
10000 00100 00001
*/