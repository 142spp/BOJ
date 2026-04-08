#include <bits/stdc++.h>
using namespace std;

bool visited[9] = {};
void dfs(vector<int>& arr, const int& n, int t , int count){
    if(visited[t]) return;
    arr.push_back(t);
    visited[t] = true;
    if(count==0){
        for(auto x : arr){
            if(x==0) continue;
            cout << x << " ";
        } cout << "\n";
    }
    for(int i=1; i<=n; i++){
        dfs(arr,n,i,count-1);
    }
    arr.pop_back();
    visited[t] = false;
}

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> arr;
    dfs(arr,n,0,m);
}