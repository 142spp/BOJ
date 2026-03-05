/*
BOJ 11659 - 구간 합 구하기 4

[문제 요약]
- N개의 수가 주어질 때, M개의 질의 (i, j)에 대해 i번째부터 j번째까지의 합을 출력한다.

[입력]
- 첫 줄: N, M
- 둘째 줄: 수 N개
- 다음 M줄: 구간 i, j (1-indexed)

[출력]
- 각 질의마다 구간 합을 한 줄에 출력

[핵심 아이디어]
- 누적합(prefix sum) 배열 pref를 만든다.
- pref[k] = 1번부터 k번까지의 합이라고 두면,
  구간 [i, j]의 합은 pref[j] - pref[i-1]로 O(1)에 구할 수 있다.

[정당성]
- pref[j]는 1..j 합, pref[i-1]는 1..(i-1) 합이므로
  두 값을 빼면 정확히 i..j 합만 남는다.

[복잡도]
- 누적합 구성: O(N)
- 질의 처리: O(M)
- 전체: O(N + M)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> pref(n + 1, 0);

    // pref[i] = 앞에서부터 i개 원소의 합 (1-indexed 누적합)
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        pref[i] = pref[i - 1] + x;
    }

    // 각 구간 [l, r]의 합 = pref[r] - pref[l-1]
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << '\n';
    }

    return 0;
}
