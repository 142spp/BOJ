#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>> n >> m; int s = n*m;
    
    while(true){
        if(n>m){
            int t = n; n = m; m = t;
        } if(n == 0) break;
        m %= n;
    }
    cout << m << "\n" << s/m;
    return 0;
}