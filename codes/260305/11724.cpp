/*
문제
방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

출력
첫째 줄에 연결 요소의 개수를 출력한다.*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 1005

int main(void){
    int n,m;
    cin.tie(NULL);
    cin >> n >> m;
    vector<int> adj[MAX];
    while(m--){
        int a,b ;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> visited(n+1,0);
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        cnt ++;
        stack<int> st; st.push(i);
        while(!st.empty()){
            int x = st.top(); st.pop();
            for(int y : adj[x]) {
                if(visited[y]) continue;
                st.push(y);
                visited[y] = true;
            }
        }
    }

    cout << cnt;
}