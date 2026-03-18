#include <bits/stdc++.h>
using namespace std;

/*
BOJ 18111 - 마인크래프트

[문제 요약]
- N x M 땅의 모든 칸 높이를 같은 높이 H로 맞춘다.
- 블록 제거: 2초, 인벤토리 +1
- 블록 쌓기: 1초, 인벤토리 -1
- 시작 인벤토리 B, 최종 높이 H는 0~256
- 최소 시간을 출력하고, 최소 시간이 여러 개면 더 높은 H를 출력

[핵심 아이디어]
- 가능한 목표 높이 H(0~256)를 모두 확인한다.
- 각 H에 대해:
  - 현재 높이 h > H 인 칸은 (h-H)개 제거 -> 시간 2*(h-H), 인벤토리 증가
  - 현재 높이 h < H 인 칸은 (H-h)개 추가 -> 시간 1*(H-h), 인벤토리 감소
- 전체 제거량 + B >= 전체 추가량이면 H를 만들 수 있다.
- 시간 최소, 동률이면 H 최대로 갱신한다.

[복잡도]
- 높이 빈도 배열(0~256)을 사용하면
  - 각 H 평가: O(257)
  - 전체: O(257*257) = 상수 시간에 가까운 매우 작은 비용
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long b;
    cin >> n >> m >> b;

    // height_count[h] = 높이 h를 가진 칸의 개수
    array<long long, 257> height_count{};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int h;
            cin >> h;
            ++height_count[h];
        }
    }

    long long best_time = LLONG_MAX;
    int best_height = -1;

    // 문제 조건상 높이 후보는 0~256 전체를 확인해도 충분히 빠르다.
    for (int target = 0; target <= 256; ++target) {
        long long remove_blocks = 0;  // target보다 높은 칸에서 제거할 총 블록 수
        long long add_blocks = 0;     // target보다 낮은 칸에 추가할 총 블록 수

        for (int h = 0; h <= 256; ++h) {
            if (h > target) {
                remove_blocks += (long long)(h - target) * height_count[h];
            } else if (h < target) {
                add_blocks += (long long)(target - h) * height_count[h];
            }
        }

        // 제거 후 인벤토리(초기 B + remove)로 add를 감당할 수 있어야 한다.
        if (b + remove_blocks < add_blocks) continue;

        long long time_spent = remove_blocks * 2 + add_blocks;

        // 최소 시간 우선, 시간이 같으면 더 높은 높이를 선택
        if (time_spent < best_time || (time_spent == best_time && target > best_height)) {
            best_time = time_spent;
            best_height = target;
        }
    }

    cout << best_time << ' ' << best_height << '\n';
    return 0;
}
