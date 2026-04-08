#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    int cur = v[0];
    int ans = v[0];
    for(int i=1; i<n; i++){
        cur = max(v[i],cur+v[i]);
        ans = max(ans,cur);
    }
    cout << ans;
}