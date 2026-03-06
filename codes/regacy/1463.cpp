#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int table[1000000] = {};

int dp(int i){
    if(table[i]!=0 || i<=1) return table[i];

    int m = dp(i-1);
    
    if(i%2==0 && dp(i/2) < m) m = dp(i/2);
    
    if(i%3==0 && dp(i/3) < m) m = dp(i/3);

    table[i] = m+1;
    return table[i];
}
  
int main(){
    int x; cin >> x;
    dp(x);
    cout << dp(x);
    return 0;
}
