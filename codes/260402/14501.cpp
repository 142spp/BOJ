#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<int> t(n);
    vector<int> p(n);
    for(int i=0; i<n; i++){
        cin >> t[i] >> p[i];
    }
    vector<int> dp(100);
    int cur_max = 0;
    for(int i=0; i<n; i++){
        cur_max = max(cur_max,dp[i]);
        if(i+t[i]>n) continue;
        dp[i+t[i]] = max(dp[i+t[i]],cur_max+p[i]);
    }
    cout << *max_element(dp.begin(),dp.end());
}