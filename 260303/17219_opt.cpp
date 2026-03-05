/*
문제 요약
- N개의 사이트 주소와 비밀번호 쌍이 주어진다.
- 이후 M개의 사이트 주소가 질의로 주어지며, 각 사이트의 비밀번호를 순서대로 출력해야 한다.

입력 핵심 조건
- N, M은 각각 최대 100,000
- 주소/비밀번호 문자열 길이는 최대 20
- 질의로 들어오는 사이트는 반드시 저장된 사이트

접근법 판단
- 현재 코드의 핵심 아이디어(사이트 -> 비밀번호 매핑 후 질의 조회)는 문제에 정확히 맞는 정답 접근이다.
- N, M이 큰 편이므로 선형 탐색은 비효율적이고, 해시 기반 딕셔너리 조회가 적합하다.

최적화 포인트
1) map(트리) 대신 unordered_map(해시) 사용: 평균 조회 O(1)
2) 질의를 vector에 저장하지 않고 입력 즉시 출력: 불필요한 메모리 사용 제거
3) reserve/max_load_factor 설정: rehash 비용과 충돌 확률 완화

시간 복잡도(평균)
- 저장: O(N)
- 질의: O(M)
- 전체: O(N + M)
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    // 대량 입출력 환경(최대 10만 줄 이상)을 고려한 표준 최적화.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 핵심 자료구조: 사이트 주소를 키로, 비밀번호를 값으로 저장한다.
    // 사용자의 원래 아이디어(딕셔너리 조회)는 그대로 재활용한다.
    unordered_map<string, string> pass;

    // 미리 버킷 여유를 확보해 삽입 중 재해시(rehash) 발생을 줄인다.
    pass.reserve(static_cast<size_t>(n) * 2);
    // 로드 팩터를 낮춰 평균 조회 성능이 안정적으로 나오게 한다.
    pass.max_load_factor(0.7f);

    // N개의 (사이트, 비밀번호) 쌍을 해시맵에 저장한다.
    for (int i = 0; i < n; ++i) {
        string site, pw;
        cin >> site >> pw;
        pass.emplace(site, pw);
    }

    // 질의는 따로 저장하지 않고 즉시 처리한다.
    // 문제에서 "질의 사이트는 반드시 존재"한다고 보장하므로 바로 조회 가능하다.
    for (int i = 0; i < m; ++i) {
        string site;
        cin >> site;

        // operator[]는 키가 없으면 새 항목을 만들 수 있으므로,
        // 안정성을 위해 find로 조회 후 출력한다.
        auto it = pass.find(site);
        if (it != pass.end()) {
            cout << it->second << '\n';
        }
    }

    return 0;
}
