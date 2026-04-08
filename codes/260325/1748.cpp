#include <bits/stdc++.h>
using namespace std;

/*
123456789 - 9개
10111213 ... 979899 - 90개
100101 .. 999 - 900개

150 - 3x51 + 2x90 + 1x9
*/

int ndigit(int m){
    int t = 0;
    while(m){ 
        m/= 10;
        t++;
    }
    return t;
}

int main(void){
    int n; cin >> n;
    int ans = 0;
    while(n){
        int m=1;
        for(int i=0; i<ndigit(n)-1; i++){ m*=10;}
        ans += ((n/m-1)*m+n%m+1)*ndigit(n);
        n = m-1;
        
    }
    cout << ans;
}