#include <bits/stdc++.h>
using namespace std;

bool visited[10001] = {};
vector<int> arr, ans;
int n, m;

void dfs(){
    if(ans.size()==m){
        for(auto x: ans){
            cout << x << " ";
        } cout << "\n"; return;
    }
    for(auto x : arr){
        if(visited[x]) continue;
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
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(),arr.end(),less());
    dfs();
}