#include <bits/stdc++.h>

using namespace std;

int table[50001] = {};
int dp(int n){
    if(table[n]) return table[n];
    int sr = (int)sqrt(n); 
    if(sr*sr == n) {
        table[n] = 1;
        return table[n];
    }
    else if(sr*sr > n) sr -=1;
    int min = 4;
    for(int i=sr; i>0; i--){
        int cur = dp(n-i*i)+dp(i*i);
        if(cur < min) min = cur;
        if(min <= 2)  {
            table[n] = min;
            return table[n];
        }
    }
    for(int i=1; i<=2/n; i++){
        int cur = dp(n-i)+dp(i);
        if(cur < min) min = cur;
        if(min <= 3)  break; 
    }
    table[n] = min;
    return table[n];
}

int main(){
    int n; cin >> n;
    cout << dp(n);
}