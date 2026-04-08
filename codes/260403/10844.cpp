#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<vector<long long>> dp(n, vector<long long>(10, 0));
    for(int i=1; i<10; i++) dp[0][i] = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<10; j++){
            if(j==0) dp[i][j] = dp[i-1][j+1]%1000000000;
            else if(j==9) dp[i][j] = dp[i-1][j-1]%1000000000;
            else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1])%1000000000;
        }
    }
    long long ans = 0;
    for(int i=0; i<10; i++) ans = (ans + dp[n-1][i])%1000000000;
    cout << ans << endl;
}

/*
1~9 -> 9
1 1 1 1 1 1 1 1 1
10,12,21,23,32,34,...,89,98 -> 17
1 2 2 2 2 2 2 2 1
101, 121, 123, 212, 231, 234, 321, 323, 343, 345, ... , 876, 878, 898, 987, 989
3 4 4 4 4 4 4 3 2 -> 30
6 7 8 8 8 8 7 5 3 -> 54

7 14 24
*/
