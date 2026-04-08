#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        int cur = 1;
        for(int i=0; i<b; i++){
            cur = (cur*a) % 10;
        }
        if(cur==0) cur =10;
        cout << cur << "\n";
    }
}