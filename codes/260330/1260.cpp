#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m, v; 
    cin >> n >> m >> v;
    vector<vector<int>> adj(n+1);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(auto& v : adj) 
        sort(v.begin(),v.end(),greater());
    deque<int> dq;
    dq.push_back(v);
    bool visited[1001] = {};
    vector<int> ans;
    while(!dq.empty()){
        int b = dq.back(); dq.pop_back();
        if(visited[b]) continue;
        visited[b] = true;
        ans.push_back(b);
        for(auto x : adj[b]){
            dq.push_back(x);
        }
    }
    for(auto a : ans) cout << a << " ";
    cout << "\n";

    ans.clear();
    for(auto& v : adj) 
        sort(v.begin(),v.end(),less());
    bool visited_[1001] = {};
    visited_[v] = true;
    dq.clear();
    dq.push_back(v);
    while(!dq.empty()){
        int f = dq.front(); dq.pop_front();
        ans.push_back(f);
        for(auto x : adj[f]){
            if(visited_[x]) continue;
            visited_[x] = true;
            dq.push_back(x);
        }
    }
    for(auto a : ans) cout << a << " ";
}