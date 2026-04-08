#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<int> dp(abs(n)+1);
    dp[0] = 0; dp[1]=1;
    for(int i=2; i<=abs(n); i++){
        if(n<0){
            dp[i] = (dp[i-2]-dp[i-1])%(int)1e9;
        }else{
            dp[i] = (dp[i-1]+dp[i-2])%(int)1e9;
        }
    }
    if(dp[abs(n)]<0) cout << -1;
    else if (dp[abs(n)]>0) cout << 1;
    else cout << 0;
    cout << "\n";
    cout << abs(dp[abs(n)]);
}