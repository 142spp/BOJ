/*
BOJ 1541 - 잃어버린 괄호

[문제 요약]
- 숫자, '+' , '-' 로 이루어진 식이 주어진다.
- 괄호를 적절히 추가해 식의 값을 최소로 만들 때의 값을 출력한다.

[입력]
- 길이 50 이하의 식 1개

[출력]
- 만들 수 있는 최소값

[핵심 아이디어 - Greedy]
- 식에서 첫 '-'가 등장한 뒤의 값들은 가능한 한 크게 묶어서 한 번에 빼는 것이 최소를 만든다.
- 즉, "첫 '-' 이전 구간은 더하고", "첫 '-' 이후 구간의 모든 수는 전부 빼면" 최솟값이다.

[왜 맞는가]
- '-' 뒤에서 '+'로 연결된 수들은 괄호로 묶으면 모두 음수 항으로 만들 수 있다.
- 최소값을 만들려면 이후 항들의 기여를 최대한 작게(더 많이 빼게) 만들어야 하므로
  첫 '-' 이후의 모든 수를 빼는 전략이 최적이다.

[복잡도]
- 식을 한 번 순회: O(L), L <= 50
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string expr;
    cin >> expr;

    int answer = 0;
    int current = 0;      // 현재 읽는 숫자
    bool minusMode = false;  // 첫 '-' 이후인지 여부

    // 마지막 숫자 처리까지 한 번에 하려고 끝에 '+'를 가상으로 붙여 처리한다.
    for (size_t i = 0; i <= expr.size(); ++i) {
        if (i < expr.size() && isdigit(static_cast<unsigned char>(expr[i]))) {
            current = current * 10 + (expr[i] - '0');
            continue;
        }

        // 숫자 하나를 다 읽었으면 answer에 반영
        if (minusMode) answer -= current;
        else answer += current;
        current = 0;

        // 실제 연산자라면 모드 갱신
        if (i < expr.size() && expr[i] == '-') {
            minusMode = true;
        }
    }

    cout << answer << '\n';
    return 0;
}
