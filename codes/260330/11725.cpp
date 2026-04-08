#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<int> v(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q; q.push(1);
    int ans[100001] = {};
    while(!q.empty()){
        auto f = q.front(); q.pop();
        for(auto a : adj[f]){
            if(ans[a]) continue;
            ans[a] = f;
            q.push(a);
        }
    }
    for(int i=2; i<=n; i++){
        cout << ans[i] << "\n";
    }
}