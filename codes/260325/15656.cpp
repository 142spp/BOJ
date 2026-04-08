#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr, ans;

void dfs(){
    if(ans.size()==m){
        for(auto x : ans){
            cout << x << " ";
        } cout << "\n"; return;
    }
    for(auto x : arr){
        ans.push_back(x);
        dfs();
        ans.pop_back();
    }

}

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    arr.resize(n);
    for(auto& x : arr) cin >> x;
    sort(arr.begin(),arr.end(),less());
    dfs();
}