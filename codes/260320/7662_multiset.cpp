#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        int k; cin >> k;
        multiset<int,greater<int>> mset;
        while(k--){
            char c; int n; cin >> c >> n;
            if(c=='D'){
                if(mset.empty()) continue;
                if(n>0) mset.erase(mset.begin()); 
                else mset.erase(prev(mset.end()));
            } else mset.insert(n);
        }
        if(mset.empty()) {cout << "EMPTY" << "\n"; continue;}
        cout << *mset.begin() << " " << *prev(mset.end()) << "\n";
    }
}