#include <bits/stdc++.h>
using namespace std;


int main(void){
    int n; cin >> n;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    // i 번째가 마지막 수
    // i 번째 이하의 수들에 대해 조사
    // j (j<i) 번째 수가 i번째 수보다 작을시
    // j 번째가 마지막 수인 수열의 크기 +1이 i 번째가 마지막 수인 수열의 크기
    vector<int> dp(n,1);
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(v[i]>v[j]) dp[i] = max(dp[j]+1,dp[i]);
        }
    }
    cout << *max_element(dp.begin(),dp.end());
}

/*
10 20 10 30 20 50


*/