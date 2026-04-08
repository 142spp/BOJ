#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> adj; 

int dijkstra(int s, int e){
    priority_queue<pair<int,int>, vector<pair<int,int>> , \
        greater<>> pq;
    pq.push({0,s});
    vector<int> dist(adj.size(),2e8);
    dist[s] = 0;
    while(!pq.empty()){
        auto f = pq.top(); pq.pop();
        int cur_d = f.first;
        int cur_v = f.second;
        if(dist[cur_v] < cur_d) continue;
        for(auto a : adj[cur_v]){
            int nxtidx = a.first;
            int nxtcst = a.second;
            if(dist[nxtidx] > dist[cur_v]+nxtcst){
                dist[nxtidx] = dist[cur_v]+nxtcst;
                pq.push({dist[nxtidx],nxtidx});
            }
        } 
    }
    return dist[e];
}

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, e ; cin >> n >> e;
    adj.resize(n+1);
    for(int i=0; i<e; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }
    int v1, v2; cin >> v1 >> v2;
    int dist_v = dijkstra(v1,v2);
    int ans = dijkstra(1,v1)+dist_v+dijkstra(v2,n);
    ans = min(ans,dijkstra(1,v2)+dist_v+dijkstra(v1,n));
    if(ans>1e8) cout << -1;
    else cout << ans;
}