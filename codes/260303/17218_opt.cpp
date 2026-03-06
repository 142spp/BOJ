#include <bits/stdc++.h>
using namespace std;

/*
BOJ 17218 - 비밀번호 만들기

[문제 요약]
- 두 문자열 A, B(대문자, 길이 <= 40)가 주어진다.
- 두 문자열에 공통으로 등장하는 "가장 긴 부분 수열(LCS)"을 출력한다.
- 정답(최장 공통 부분 수열)은 항상 유일하게 존재한다.

[핵심 아이디어]
- dp[i][j] := A의 앞 i글자, B의 앞 j글자를 봤을 때 LCS 길이
  - A[i-1] == B[j-1] 이면 dp[i][j] = dp[i-1][j-1] + 1
  - 다르면 dp[i][j] = max(dp[i-1][j], dp[i][j-1])
- 길이 DP를 채운 뒤, (n, m)에서 역추적하며 실제 문자열을 복원한다.
  - 문자가 같으면 그 문자는 LCS에 포함되므로 답에 추가하고 대각선으로 이동
  - 다르면 더 큰 값을 준 쪽으로 이동

[복잡도]
- 시간: O(n * m) (최대 40 * 40 = 1600)
- 메모리: O(n * m)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;

    const int n = static_cast<int>(A.size());
    const int m = static_cast<int>(B.size());

    // dp 테이블: LCS 길이를 저장
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (A[i - 1] == B[j - 1]) {
                // 마지막 글자가 같다면 이전 접두사의 최적해 + 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // 마지막 글자가 다르면 둘 중 하나를 버리는 경우의 최댓값
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 디버그용: 완성된 DP 테이블을 표 형태로 출력한다.
    // true로 바꾸면 stderr로 테이블을 찍고, false면 아무것도 출력하지 않는다.
    // (BOJ 채점 출력은 stdout 기준이므로 정답 출력에는 영향 없음)
    constexpr bool kPrintDpTable = true;
    if (kPrintDpTable) {
        cerr << "\n[DP Table]\n";
        cerr << setw(4) << " ";
        cerr << setw(5) << "Ø";
        for (int j = 0; j < m; ++j) cerr << setw(4) << B[j];
        cerr << '\n';

        for (int i = 0; i <= n; ++i) {
            if (i == 0) cerr << setw(5) << "Ø";
            else cerr << setw(4) << A[i - 1];

            for (int j = 0; j <= m; ++j) {
                cerr << setw(4) << dp[i][j];
            }
            cerr << '\n';
        }
        cerr << '\n';
    }

    // 역추적으로 실제 LCS 문자열 복원
    string lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (A[i - 1] == B[j - 1]) {
            // 공통 문자 확정: 결과에 넣고 대각선으로 이동
            lcs.push_back(A[i - 1]);
            --i;
            --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            // 위쪽이 더 길거나 같으면 i 감소
            --i;
        } else {
            // 왼쪽이 더 길면 j 감소
            --j;
        }
    }

    reverse(lcs.begin(), lcs.end());
    cout << lcs << '\n';
    return 0;
}
