/*
문제 요약
- M개의 우주가 있고, 각 우주마다 N개 행성 크기가 주어진다.
- 두 우주 A, B에 대해 모든 i, j에서
  Ai < Aj 이면 Bi < Bj,
  Ai = Aj 이면 Bi = Bj,
  Ai > Aj 이면 Bi > Bj
  를 만족하면 균등한 우주다.
- 균등한 우주 쌍의 개수를 출력한다.

풀이 아이디어 (직접 비교, 좌표압축 없음)
- 우주 쌍 (u, v)을 하나 고른 뒤, 모든 행성 쌍 (i, j), i < j에 대해
  두 우주의 대소관계를 직접 비교한다.
- 어느 한 쌍이라도 대소관계(작다/같다/크다)가 다르면 그 우주 쌍은 탈락.
- 끝까지 모두 같으면 균등한 우주 쌍이므로 정답 +1.

복잡도
- 우주 쌍: O(M^2)
- 각 우주 쌍 검증: O(N^2)
- 총 O(M^2 * N^2), 메모리 O(M * N)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<vector<int>> universe(M, vector<int>(N));
    for (int u = 0; u < M; ++u) {
        for (int i = 0; i < N; ++i) cin >> universe[u][i];
    }

    long long answer = 0;

    for (int u = 0; u < M; ++u) {
        for (int v = u + 1; v < M; ++v) {
            bool same = true;

            for (int i = 0; i < N && same; ++i) {
                for (int j = i + 1; j < N; ++j) {
                    int a = universe[u][i];
                    int b = universe[u][j];
                    int c = universe[v][i];
                    int d = universe[v][j];

                    // sign(a-b)와 sign(c-d)가 같아야 대소/동등 관계가 일치한다.
                    int rel1 = (a < b ? -1 : (a > b ? 1 : 0));
                    int rel2 = (c < d ? -1 : (c > d ? 1 : 0));
                    if (rel1 != rel2) {
                        same = false;
                        break;
                    }
                }
            }

            if (same) ++answer;
        }
    }

    cout << answer << '\n';
    return 0;
}
