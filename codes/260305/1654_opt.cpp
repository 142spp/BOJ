/*
BOJ 1654 - 랜선 자르기

[문제 요약]
- K개의 기존 랜선을 잘라 길이가 같은 랜선을 N개 이상 만들 때,
  가능한 랜선 길이의 최댓값을 구한다.

[입력]
- 첫 줄: K, N
- 다음 K줄: 각 랜선 길이 (자연수)

[출력]
- 만들 수 있는 최대 랜선 길이 (정수)

[핵심 아이디어]
- 길이 L로 잘랐을 때 만들 수 있는 개수 f(L) = sum(wire[i] / L)
- L이 커질수록 f(L)는 감소(단조)하므로 이분 탐색 가능

[탐색 구간]
- low = 1 (0은 길이로 불가능, 0으로 나누기 방지)
- high = 가장 긴 랜선 길이

[판정]
- f(mid) >= N 이면 mid 길이는 가능 => 더 긴 길이 탐색(low = mid + 1)
- f(mid) < N 이면 mid 길이는 불가능 => 길이를 줄임(high = mid - 1)

[정답]
- 가능한 길이 중 최대값을 저장해서 출력

[복잡도]
- O(K log MaxLen), MaxLen <= 2^31-1
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, n;
    cin >> k >> n;

    vector<long long> wires(k);
    long long high = 0;  // 가능한 최대 길이의 상한: 입력 랜선 중 최댓값
    for (long long &x : wires) {
        cin >> x;
        high = max(high, x);
    }

    long long low = 1;
    long long answer = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        // mid 길이로 만들 수 있는 랜선 개수 계산
        long long cnt = 0;
        for (long long x : wires) {
            cnt += x / mid;
        }

        if (cnt >= n) {
            // mid 길이로 N개 이상 가능 -> 정답 후보 갱신 후 더 긴 길이 시도
            answer = mid;
            low = mid + 1;
        } else {
            // mid 길이로 N개 불가 -> 길이를 줄여야 함
            high = mid - 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
