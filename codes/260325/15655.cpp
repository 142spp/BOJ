#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr, ans;
bool visited[10001] = {};

void dfs(){
    if(ans.size()==m){
        for(auto x : ans){
            cout << x << " ";
        } cout << "\n"; return;
    }
    int last = ans.empty() ? 0 : ans.back();
    for(auto x : arr){
        if(x < last || visited[x]) continue;
        visited[x] = true;
        ans.push_back(x);
        dfs();
        ans.pop_back();
        visited[x] = false;
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