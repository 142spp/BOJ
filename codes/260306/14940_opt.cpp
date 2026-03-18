/*
BOJ 14940 - 쉬운 최단거리

[문제 요약]
- n x m 지도에서:
  - 0: 갈 수 없는 땅
  - 1: 갈 수 있는 땅
  - 2: 목표 지점 (정확히 1개)
- 상하좌우로만 이동 가능할 때, 모든 칸에서 목표 지점까지의 최단거리를 출력한다.

[출력 규칙]
- 원래 0인 칸은 0 출력
- 원래 1 또는 2인 칸 중 목표에 도달 불가능하면 -1 출력
- 목표 지점은 0 출력

[핵심 아이디어]
- "모든 칸 -> 목표" 최단거리는, 간선 가중치가 동일(1)인 격자에서
  "목표 -> 모든 칸" BFS 한 번으로 동시에 구할 수 있다.
- 따라서 목표 지점에서 BFS를 시작해 각 칸의 거리(dist)를 채운다.

[복잡도]
- 시간: O(n*m) (각 칸을 최대 1번 방문)
- 공간: O(n*m) (지도 + 거리 + 큐)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    const int total = n * m;
    vector<int> board(total);
    vector<int> dist(total, -1); // -1: 아직 도달하지 못함

    int start = -1; // 목표 지점(값 2)의 1차원 인덱스

    // 입력을 1차원 배열로 저장해 캐시 친화적으로 처리한다.
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            int v;
            cin >> v;
            const int idx = r * m + c;
            board[idx] = v;
            if (v == 2) start = idx;
        }
    }

    queue<int> q;
    q.push(start);
    dist[start] = 0;

    // 4방향 이동 벡터
    constexpr int dr[4] = {1, -1, 0, 0};
    constexpr int dc[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        const int cur = q.front();
        q.pop();

        const int r = cur / m;
        const int c = cur % m;

        for (int k = 0; k < 4; ++k) {
            const int nr = r + dr[k];
            const int nc = c + dc[k];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

            const int nxt = nr * m + nc;

            // 0은 애초에 이동 불가, dist != -1이면 이미 최단거리 확정 방문
            if (board[nxt] == 0 || dist[nxt] != -1) continue;

            dist[nxt] = dist[cur] + 1;
            q.push(nxt);
        }
    }

    // 출력 규칙에 맞춰 정리:
    // - board==0: 항상 0
    // - board!=0: dist 값(도달 못하면 -1 유지)
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            const int idx = r * m + c;
            if (board[idx] == 0)
                cout << 0;
            else
                cout << dist[idx];
            if (c + 1 < m) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
