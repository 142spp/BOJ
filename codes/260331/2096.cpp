#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> maxdp(3);
    vector<int> mindp(3);
    while(n--){
        int s[3];
        cin >> s[0] >> s[1] >> s[2];
        vector<int> ndp(3);

        ndp[0] = max(maxdp[0],maxdp[1])+s[0];
        ndp[0] = min(mindp[0],mindp[1])+s[0];

        ndp[1] = max({maxdp[0],maxdp[1],maxdp[2]})+s[1];
        ndp[1] = min({mindp[0],mindp[1],mindp[2]})+s[1];

        ndp[2] = max(maxdp[1],maxdp[2])+s[2];
        ndp[2] = min(mindp[1],mindp[2])+s[2];
        
        maxdp = ndp;
        mindp = ndp;
    }
    
    cout << max({maxdp[0],maxdp[1],maxdp[2]}) << " " << \
        min({mindp[0],mindp[1],mindp[2]});
}