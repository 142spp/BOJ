#include <bits/stdc++.h>

using namespace std;

int table[201][201]={{},};
int dp(int n, int k){
    if(k<=1) return 1;
    if(table[n][k]) return table[n][k];
    for(int i=0; i<=n; i++)
        for(int j=1; j<k; j++)
            table[n][k] += dp(i,j)*dp(n-i,k-j);
            
    return table[n][k];
}

int main(){
    int n, k; cin >> n >> k;
    cout << dp(n,k);
}

