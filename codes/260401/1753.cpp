#include <bits/stdc++.h>
using namespace std;

int main(void){
    int v,e; cin >> v >> e;
    int s; cin >> s;
    vector<vector<pair<int,int>>> adj(v+1);
    for(int i=0; i<e; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>> \
        ,greater<>> pq;
    vector<int> dist(v+1,INT_MAX);
    dist[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        auto f = pq.top(); pq.pop();
        if(dist[f.second] < f.first) continue;
        for(auto a : adj[f.second]){
            if(dist[a.first] > dist[f.second] + a.second){
                dist[a.first] = dist[f.second] + a.second;
                pq.push({dist[a.first],a.first});
            }
        }
    }
    for(int i=1; i<=v; i++){
        if(dist[i]==INT_MAX) cout << "INF";
        else cout << dist[i];
        cout << "\n";
    }
}