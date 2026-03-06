#include <bits/stdc++.h>
using namespace std;

/*
BOJ 2606 - 바이러스

[문제 요약]
- 1번 컴퓨터에서 시작해 네트워크 연결(무방향 간선)을 따라 전염될 수 있는
  컴퓨터의 수를 구한다.
- 단, 출력은 "1번을 제외한" 감염 컴퓨터 수다.

[입력/출력]
- 입력:
  1) 컴퓨터 수 N (1 <= N <= 100)
  2) 직접 연결된 쌍의 수 M
  3) M개의 간선 (a, b)
- 출력: 1번에서 도달 가능한 정점 수 - 1

[알고리즘]
- 그래프를 인접 리스트로 구성한 뒤 BFS(또는 DFS) 1회 수행.
- 방문 배열로 중복 방문을 막아 각 정점을 정확히 1번만 센다.

[정당성]
- BFS는 시작점 1에서 도달 가능한 모든 정점을 빠짐없이 방문한다.
- 방문 체크로 같은 정점을 중복 처리하지 않으므로 카운트가 정확하다.
- 따라서 방문된 정점 수에서 1번 자신을 뺀 값이 정답이다.

[복잡도]
- 시간: O(N + M)
- 메모리: O(N + M)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;

    int infected = 0;  // 1번을 제외한 감염 수

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if (visited[nxt]) continue;
            visited[nxt] = true;  // 큐에 넣는 순간 방문 처리해 중복 삽입 방지
            q.push(nxt);
            ++infected;
        }
    }

    cout << infected << '\n';
    return 0;
}
