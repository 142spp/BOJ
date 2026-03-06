/*
BOJ 1012 - 유기농 배추

[문제 요약]
- 배추가 심어진 칸(1)들이 주어질 때, 상하좌우로 연결된 배추 무리(연결요소) 개수를 구한다.
- 각 연결요소마다 지렁이 1마리가 필요하므로, 정답은 연결요소 개수다.

[입력]
- T: 테스트 케이스 수
- 각 케이스마다 M(가로), N(세로), K(배추 개수)
- 이어서 K줄: 배추 좌표 (x, y), 0 <= x < M, 0 <= y < N

[출력]
- 케이스마다 필요한 최소 지렁이 수

[알고리즘]
- 그래프 탐색(BFS)으로 연결요소 개수를 센다.
- 격자에서 배추 칸을 시작점으로 BFS를 한 번 수행하면 해당 무리를 모두 방문 처리한다.
- 아직 방문하지 않은 배추 칸마다 BFS를 시작하고 카운트를 1 증가시킨다.

[정당성]
- 상하좌우 인접만 같은 무리로 정의되므로, 격자 그래프의 연결요소 개수를 세는 문제와 동일하다.
- BFS는 시작점과 같은 연결요소의 모든 정점을 정확히 한 번 방문한다.
- 모든 칸을 순회하며 미방문 배추에서 BFS를 시작하면 각 연결요소를 정확히 한 번씩 센다.

[복잡도]
- 각 칸은 최대 한 번 방문: O(N*M)
- 제약(N, M <= 50)에서 충분히 빠름.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};

    while (t--) {
        int m, n, k;  // m: width(x), n: height(y)
        cin >> m >> n >> k;

        vector<vector<int>> field(n, vector<int>(m, 0));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // 입력 좌표는 (x, y)이므로 field[y][x]에 저장한다.
        while (k--) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        int worms = 0;
        queue<pair<int, int>> q;

        for (int y = 0; y < n; ++y) {
            for (int x = 0; x < m; ++x) {
                if (!field[y][x] || visited[y][x]) continue;

                // 새 연결요소 발견: 지렁이 1마리 추가
                ++worms;
                visited[y][x] = 1;
                q.push({x, y});

                while (!q.empty()) {
                    auto [cx, cy] = q.front();
                    q.pop();

                    for (int dir = 0; dir < 4; ++dir) {
                        int nx = cx + dx[dir];
                        int ny = cy + dy[dir];

                        // 격자 범위 밖이면 무시
                        if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                        if (!field[ny][nx] || visited[ny][nx]) continue;

                        visited[ny][nx] = 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        cout << worms << '\n';
    }

    return 0;
}
