#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr, ans;
int cnt[10001] = {};

void dfs(){
    if((int)ans.size()==m){
        for(auto x : ans){
            cout << x << " ";
        } cout << "\n"; return;
    }
    for(auto x : arr){
        if(cnt[x]<=0) continue;
        cnt[x]--;
        ans.push_back(x);
        dfs();
        ans.pop_back();
        cnt[x]++;
    }

}

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    arr.resize(n);
    for(auto& x : arr) {
        int c; cin >>c ;
        x = c; 
        cnt[c]++;
    }
    set<int> s;
    for(auto x : arr) s.insert(x);
    arr.clear();
    for(auto x: s) arr.push_back(x);
    dfs();
}