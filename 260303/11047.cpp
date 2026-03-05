#include <bits/stdc++.h>

using namespace std;

map<int,int> table;
int dp(const vector<int>& A, int k) { 
    if (table.find(k) != table.end()) return table[k];
    for (auto x : A){
        if (x <= k) {
            int r = k/x ;
            int ans = dp(A, k-x*r) + r;
            table.insert({k,ans});
            return ans;
        }
    }
    return 0;
}

int main(void) {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto& x : A) cin >> x;
    reverse(A.begin(), A.end());
    // for (auto x : A) cout << x << endl;
    cout << dp(A,k);

    return 0;
}