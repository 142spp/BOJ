/*
문제
수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다. 둘째 줄에는 N개의 수가 주어진다. 수는 1,000보다 작거나 같은 자연수이다. 셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.

출력
총 M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합을 출력한다.*/

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin >> n >> m;
    vector<int> v(n);
    for(auto& x: v) cin >> x;

    vector<int> dp(n+1,0);
    for (int i=1; i<=n; i++){
        dp[i] = dp[i-1] + v[i-1];
    }

    while(m--){
        int i,j; cin >> i >> j;
        cout << dp[j]-dp[i-1] << '\n';
    }
}