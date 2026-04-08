#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    while(m--){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    deque<int> q;
    int ans = 0;
    q.push_back(1);
    bool visited[101] = {};
    visited[1] = true;
    while(!q.empty()){
        int f = q.front(); q.pop_front();
        for(auto x : v[f]){
            if(visited[x]) continue;
            visited[x] = true;
            q.push_back(x);
        }        
        ans++;
    }
    cout << ans-1;
}