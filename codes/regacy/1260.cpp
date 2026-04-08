#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vc;
int visited[1001]={};
vector<int> answ;

void dfs(int v){
    visited[v] = true;
    answ.push_back(v);
    for(auto c : vc[v]){
        if(!visited[c]) dfs(c);
    }
    //visited[v] = false;
    //answ.pop_back();
    return;
}

queue<int> q;
void bfs(int v){
    q.push(v);
    visited[v] = true;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        answ.push_back(cur);
        for(auto i : vc[cur]){
            if(!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main(){
    int n,m,v; cin >> n >> m >> v;
    vc.resize(n+1,vector<int>());
    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        vc[a].push_back(b);
        vc[b].push_back(a);
    }
    for(int i=0; i<=n; i++){
        sort(vc[i].begin(),vc[i].end());
    }
    dfs(v);
    for(auto ans : answ) cout << ans << " ";
    cout << "\n";
    memset(visited,false,sizeof(visited)); answ.clear();
    bfs(v);
    for(auto ans : answ) cout << ans << " ";
    cout << "\n";
    return 0;
}