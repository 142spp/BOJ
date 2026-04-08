#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    vector<int> dp(n);
    for(int i=0; i<n; i++){
        dp[i] = v[i];
        for(int j=0; j<i; j++){
            if(v[i]>v[j]){
                dp[i] = max(dp[i],dp[j]+v[i]);
            }
        }
    }
    cout << *max_element(dp.begin(),dp.end());
}