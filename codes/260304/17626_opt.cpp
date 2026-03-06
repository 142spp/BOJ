/*
BOJ 17626 - Four Squares

[문제 요약]
- 자연수 n(1 <= n <= 50,000)을 제곱수들의 합으로 나타낼 때,
  필요한 제곱수 개수의 최솟값을 구한다.

[입력]
- 정수 n 하나

[출력]
- n을 만들기 위한 제곱수 개수의 최솟값

[핵심 아이디어 - DP]
- dp[i] := i를 제곱수 합으로 나타낼 때 필요한 최소 개수
- 점화식:
  dp[i] = min(dp[i - j*j] + 1)  (단, j*j <= i)
- 의미:
  마지막에 j*j를 하나 사용했다고 보면,
  나머지 i - j*j를 만드는 최소 개수에 1을 더하면 된다.

[정당성]
- i를 만드는 모든 표현은 "마지막 제곱수 하나"를 기준으로 분해 가능하다.
- 가능한 모든 j*j를 확인해 최소를 취하므로 최적해를 놓치지 않는다.

[복잡도]
- i마다 가능한 j는 최대 sqrt(i)
- 전체: O(n * sqrt(n)), n=50,000에서 충분히 빠름.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    const int INF = 1e9;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;  // 0은 제곱수 0개로 표현 가능

    for (int i = 1; i <= n; ++i) {
        // i에서 사용할 수 있는 모든 제곱수 j*j를 시도
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[n] << '\n';
    return 0;
}
