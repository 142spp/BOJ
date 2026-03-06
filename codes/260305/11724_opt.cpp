/*
BOJ 11724 - 연결 요소의 개수

[문제 요약]
- 방향 없는 그래프가 주어질 때, 연결 요소(Connected Component)의 개수를 구한다.

[입력]
- 첫 줄: 정점 수 N, 간선 수 M
- 다음 M줄: 간선의 양 끝점 u, v (무방향)

[출력]
- 연결 요소의 개수

[핵심 제약]
- 1 <= N <= 1000
- 0 <= M <= N*(N-1)/2

[알고리즘]
- 모든 정점을 1..N 순회한다.
- 아직 방문하지 않은 정점을 발견하면, 그 정점에서 반복 DFS(스택)를 실행한다.
- DFS 1회가 끝날 때마다 연결 요소 1개를 찾은 것이므로 카운트를 증가시킨다.

[정당성]
- 무방향 그래프에서 한 정점에서 DFS/BFS로 도달 가능한 정점 집합은 정확히 그 정점이 속한 연결 요소와 같다.
- 방문하지 않은 정점에서 DFS를 시작할 때마다 새로운 연결 요소 하나를 정확히 한 번씩 세게 된다.

[복잡도]
- 시간: O(N + M)
- 공간: O(N + M)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 인접 리스트: 정점 번호가 1..N 이므로 n+1 크기로 생성
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    int components = 0;

    for (int start = 1; start <= n; ++start) {
        if (visited[start]) continue;

        // start가 아직 방문되지 않았으므로 새로운 연결 요소를 발견한 것
        ++components;

        // 반복 DFS: 시작 정점을 즉시 방문 처리하여 중복 push를 방지
        stack<int> st;
        st.push(start);
        visited[start] = true;

        while (!st.empty()) {
            int cur = st.top();
            st.pop();

            for (int nxt : graph[cur]) {
                if (visited[nxt]) continue;
                visited[nxt] = true;
                st.push(nxt);
            }
        }
    }

    cout << components << '\n';
    return 0;
}
