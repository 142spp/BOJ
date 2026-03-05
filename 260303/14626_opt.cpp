#include <bits/stdc++.h>
using namespace std;

/*
BOJ 14626 - ISBN

[문제 요약]
- 길이 13의 ISBN 문자열이 주어진다.
- 숫자 한 자리(체크기호가 아닌 위치)가 '*'로 훼손되어 있다.
- ISBN 규칙:
  a+3b+c+3d+...+3l+m ≡ 0 (mod 10)
  (왼쪽부터 0-index 기준 짝수 위치 가중치 1, 홀수 위치 가중치 3)
- '*'에 들어갈 숫자(0~9)를 찾아 출력한다.

[알고리즘]
1) '*'를 제외한 자리의 (숫자 * 가중치) 합을 sum으로 계산한다.
2) '*' 위치의 가중치를 w(1 또는 3)라고 하면,
     sum + w*x ≡ 0 (mod 10)
   을 만족하는 x가 정답이다.
3) x를 0~9에서 선형 탐색해도 상수 시간이지만,
   식을 정리해 x = ((10 - (sum % 10)) % 10) / w 형태로 단순 나눗셈이 안 된다(모듈러에서).
   따라서 안전하고 명확하게 0~9를 확인한다. (최대 10번)

[복잡도]
- 시간: O(13 * 10) = O(1)
- 메모리: O(1)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;  // length = 13

    int sum = 0;
    int star_idx = -1;

    for (int i = 0; i < 13; ++i) {
        if (s[i] == '*') {
            star_idx = i;
            continue;
        }

        const int digit = s[i] - '0';
        const int weight = (i % 2 == 0 ? 1 : 3);
        sum += digit * weight;
    }

    const int star_weight = (star_idx % 2 == 0 ? 1 : 3);

    for (int x = 0; x <= 9; ++x) {
        if ((sum + star_weight * x) % 10 == 0) {
            cout << x << '\n';
            return 0;
        }
    }

    return 0;
}
