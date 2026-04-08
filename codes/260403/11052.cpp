#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin>>n;
    vector<int> v(n+1);
    for(int i=1; i<n+1; i++) cin >> v[i];
    vector<int> dp(n+1);
    for(int i=1; i<n+1; i++){
        for(int j=i; j<n+1; j++){
            dp[j] = max(dp[j-i]+v[i],dp[j]);
        }
    }
    cout << dp[n];
    return 0;
}
