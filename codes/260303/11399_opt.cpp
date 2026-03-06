#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    long long prefix = 0;
    long long answer = 0;
    for (int t : p) {
        prefix += t;
        answer += prefix;
    }

    cout << answer << '\n';
    return 0;
}
