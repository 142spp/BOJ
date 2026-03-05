/*
문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.*/

#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v, int n){
    visited[v] = true;
    cout << v << " "; 
    for (auto a : adj[v]){
        if (visited[a]) continue;
        dfs(a,n);
    }
}

queue<int> q;
void bfs(int v, int n){
    q.push(v);
    visited[v] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        cout << x << " ";
        for (auto a: adj[x]){
            if(visited[a]) continue;
            q.push(a);
            visited[a] = true;
        }
    }
}

int main(void){
    int n,m,v;
    cin >> n >> m >> v;
    adj.resize(n+1);
    visited.resize(n+1,false);
    while (m--){
        int x,y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (auto& a : adj){
        sort(a.begin(),a.end());
    }

    dfs(v,n);
    visited.assign(n+1,false);
    cout << "\n";
    bfs(v,n);
}