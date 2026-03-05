#include <bits/stdc++.h>
using namespace std;

/*
BOJ 2579 - 계단 오르기

[문제 요약]
- 각 계단 점수가 주어질 때, 마지막 계단은 반드시 밟으면서 얻을 수 있는 최대 점수를 구한다.
- 한 번에 1칸 또는 2칸 이동 가능.
- 연속된 3개의 계단을 모두 밟는 것은 금지.
- 계단 수 N <= 300, 점수 <= 10,000.

[DP 정의]
- dp[i] := i번째 계단(1-indexed)을 "반드시 밟고" 도착했을 때의 최대 점수

[점화식]
- i번째 계단에 오려면 두 가지 합법 경로만 가능:
  1) (i-2) -> i : dp[i-2] + s[i]
  2) (i-3) -> (i-1) -> i : dp[i-3] + s[i-1] + s[i]
  따라서 dp[i] = max(dp[i-2] + s[i], dp[i-3] + s[i-1] + s[i])

[초기값]
- dp[1] = s[1]
- dp[2] = s[1] + s[2]
- dp[3] = max(s[1] + s[3], s[2] + s[3])

[구현 포인트]
- 점화식에 필요한 것은 dp[i-2], dp[i-3]뿐이므로
  배열 전체 대신 rolling 변수 3개(dp[i-3], dp[i-2], dp[i-1])만 유지한다.

[복잡도]
- 시간: O(N)
- 메모리: O(1) (입력 배열 제외)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; ++i) cin >> s[i];

    if (n == 1) {
        cout << s[1] << '\n';
        return 0;
    }
    if (n == 2) {
        cout << s[1] + s[2] << '\n';
        return 0;
    }

    int dp_im3 = s[1];                         // dp[1]
    int dp_im2 = s[1] + s[2];                  // dp[2]
    int dp_im1 = max(s[1] + s[3], s[2] + s[3]);  // dp[3]

    for (int i = 4; i <= n; ++i) {
        const int cur = max(dp_im2 + s[i], dp_im3 + s[i - 1] + s[i]);
        dp_im3 = dp_im2;
        dp_im2 = dp_im1;
        dp_im1 = cur;
    }

    cout << dp_im1 << '\n';
    return 0;
}
