#include <bits/stdc++.h>

using namespace std;

int table[1001]={};

int dp(int n){
    if(table[n]!=0) return table[n];
    if(n==1) return 1;
    if(n==2) return 2;
    table[n] = (dp(n-1)+dp(n-2))%10007;
    return table[n];
}

int main(){
    int n; cin >> n;
    cout << dp(n);
}