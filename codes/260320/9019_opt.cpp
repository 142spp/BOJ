#include <bits/stdc++.h>
using namespace std;

/*
문제 요약
- 시작 값 A를 목표 값 B로 바꾸는 최소 명령열을 구한다.
- 사용할 수 있는 연산은 D, S, L, R 네 가지이고 값의 범위는 0~9999이다.
- 테스트 케이스마다 가능한 최소 명령열 중 아무거나 하나 출력하면 된다.

핵심 아이디어
- 각 숫자를 정점, 명령 적용 결과를 간선으로 보는 최단 경로 문제다.
- 모든 간선 비용이 1이므로 BFS를 사용하면 최소 명령 횟수를 보장할 수 있다.
- 기존 문자열 누적 방식 대신, 각 정점의 부모 정점과 마지막 명령만 저장한 뒤
  목표 정점에서 시작 정점까지 역추적해 정답을 복원한다.

복잡도
- 한 테스트 케이스마다 정점은 최대 10000개, 각 정점에서 간선 4개를 확인한다.
- 시간복잡도: O(10000)
- 공간복잡도: O(10000)
*/

static inline int opD(int x) {
    return (x * 2) % 10000;
}

static inline int opS(int x) {
    return x == 0 ? 9999 : x - 1;
}

static inline int opL(int x) {
    return (x % 1000) * 10 + x / 1000;
}

static inline int opR(int x) {
    return (x % 10) * 1000 + x / 10;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        vector<int> parent(10000, -1);
        vector<char> how(10000, 0);
        vector<bool> visited(10000, false);
        queue<int> q;

        // 시작점은 부모가 없으므로 자기 자신으로 표시해 역추적 종료 기준으로 사용한다.
        visited[A] = true;
        parent[A] = A;
        q.push(A);

        while (!q.empty() && !visited[B]) {
            int cur = q.front();
            q.pop();

            const int nexts[4] = {opD(cur), opS(cur), opL(cur), opR(cur)};
            const char cmds[4] = {'D', 'S', 'L', 'R'};

            // BFS에서 처음 방문한 경로가 곧 최소 명령열이므로 그 정보만 저장하면 충분하다.
            for (int i = 0; i < 4; ++i) {
                int nxt = nexts[i];
                if (visited[nxt]) continue;

                visited[nxt] = true;
                parent[nxt] = cur;
                how[nxt] = cmds[i];
                q.push(nxt);
            }
        }

        string answer;
        for (int cur = B; cur != A; cur = parent[cur]) {
            answer += how[cur];
        }
        reverse(answer.begin(), answer.end());
        cout << answer << '\n';
    }

    return 0;
}
