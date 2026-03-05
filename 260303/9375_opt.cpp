#include <bits/stdc++.h>
using namespace std;

/*
BOJ 9375 - 패션왕 신해빈

[문제 요약]
- 의상 이름/종류가 주어질 때, "알몸이 아닌" 모든 서로 다른 착용 조합 수를 구한다.
- 한 종류에서는 최대 1개만 착용 가능.
- 테스트 케이스마다 결과를 출력.

[핵심 아이디어: 조합의 곱셈 원리]
- 어떤 종류에 옷이 k개 있으면 선택지는 (입지 않음 1가지 + 옷 k가지) = k+1가지.
- 종류가 c개라면 전체 조합 수는 각 종류 선택지의 곱:
    (k1+1) * (k2+1) * ... * (kc+1)
- 여기에는 "아무것도 입지 않음" 1가지가 포함되므로 최종 답은 1을 뺀다.

[구현 방향]
- 의상 이름 자체는 계산에 필요 없으므로 버린다.
- 종류별 개수만 unordered_map<string, int>에 카운트한다.

[복잡도]
- 시간: O(n) (테스트케이스당)
- 메모리: O(종류 수)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_map<string, int> cnt_by_type;
        cnt_by_type.reserve(static_cast<size_t>(n) * 2 + 1);

        for (int i = 0; i < n; ++i) {
            string name, type;
            cin >> name >> type;
            ++cnt_by_type[type];
        }

        long long ways = 1;
        for (const auto& [type, cnt] : cnt_by_type) {
            (void)type;  // key는 순회용, 계산엔 개수만 사용
            ways *= (cnt + 1LL);
        }

        cout << (ways - 1) << '\n';
    }

    return 0;
}
