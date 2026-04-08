#include <bits/stdc++.h>
using namespace std;

int n,m;
map<int,int> arr;
vector<int> ans;
void dfs(){
    if((int)ans.size()==m){
        for(auto x:ans){
            cout << x << " ";
        } cout << "\n"; return;
    }
    int last= ans.empty() ? 0 : ans.back();
    for(auto& x : arr){
        if(x.first < last) continue;
        if(x.second <= 0) continue;
        x.second--;
        ans.push_back(x.first);
        dfs();
        ans.pop_back();
        x.second++;
    }
}

int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        int c; cin >> c;
        arr[c]++;
    }
    dfs();
}

