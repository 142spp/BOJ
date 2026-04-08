#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr,ans;
void dfs(){
    if((int)ans.size()==m){
        for(auto x:ans){
            cout << x << " ";
        } cout << "\n"; return;
    }
    int last = ans.empty() ? 0 : ans.back();
    for(auto x : arr){
        if(x<last) continue;
        ans.push_back(x);
        dfs();
        ans.pop_back();
    }
}

int main(void){
    cin >> n >> m;
    arr.resize(n);
    for(auto& x : arr) cin >> x;
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    dfs();
}

