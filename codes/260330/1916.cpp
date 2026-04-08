#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n+1);
    vector<vector<int>> adj(n+1,vector<int>(n+1,1e5));
    while(m--){
        int a, b, w; cin >> a >> b >> w;
        adj[a][b] = min(w,adj[a][b]);
        v[a].push_back(b);
    }
    int s, t; cin >> s >> t;
    priority_queue<pair<int,int>, \
        vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,s});
    bool visited[1001] = {};
    vector<int> dist(n+1,1e9);
    dist[s] = 0;
    while(!pq.empty()){
        auto f = pq.top(); pq.pop();
        for(auto x : v[f.second]){
            if(visited[x]) continue;
            if(dist[x] > dist[f.second]+adj[f.second][x]){
                dist[x] = dist[f.second]+adj[f.second][x];
                pq.push({dist[x],x});
            }
        }
    }
    cout << dist[t];
}