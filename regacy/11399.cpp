#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vc;
    while(n--){
        int i; cin >> i;
        vc.push_back(i);
    }
    sort(vc.begin(),vc.end());
    int cur = 0;
    int total = 0;
    for(auto i : vc){
        cur += i;
        total += cur;
    }   
    cout << total;
    return 0;
}