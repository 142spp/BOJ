#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n; cin >> n;
	long long dp[41] = {0,1,2,5};
	for(int i=4; i<=n; i++){
		dp[i] = dp[i-3] * 2 + dp[i-2] + dp[i-1];
	}
	cout << dp[n];
}