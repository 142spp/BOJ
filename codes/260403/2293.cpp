#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    vector<int> dp(k+1);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        int cost = v[i-1];
        for(int j=cost; j<=k; j++){
            dp[j] += dp[j-cost];
        }
    }
    cout << dp[k];
    return 0;
}

/*
1 2 5
1 - 1
11, 2 -2 
111, 1 2 - 2
1111, 11 2, 2 2 - 3
11111, 111 2, 1 2 2, 5 -4
111111, 1111 2, 11 22, 222, 1 5,  -5
*/