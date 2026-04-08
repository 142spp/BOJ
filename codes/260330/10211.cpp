#include <bits/stdc++.h>
using namespace std;

// 카데인 알고리즘 

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(auto& c : v) cin >> c;
        int maximum = INT_MIN;
        int cur = 0;
        for(auto x : v){
            cur = max(x,cur+x);
            maximum = max(cur,maximum);
        }
        cout << maximum << "\n";
    }

}