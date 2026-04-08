#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    uint64_t n, m; cin >> n >> m;
    bool isprime[1000001];
    fill(isprime,isprime+1000000,true);
    for(int i=2; i<=sqrt(m);i++){
        if(isprime[i]==false) continue;
        for(int j=2; i*j<=sqrt(m);j++){
            isprime[i*j] = false;
        }
    }
    int ans = 0;
    bool isnono[1000001];
    fill(isnono,isnono+1000000,true);
    for(uint64_t i=2; i<=sqrt(m);i++){
        if(!isprime[i]) continue;
        uint64_t cur = i*i*ceil((double)n/(double)(i*i));
        while(cur<=m){
            isnono[cur-n] = false;
            cur += i*i;
        }
    }
    for(int i=0; i<(int)(m-n+1); i++) if(isnono[i]) ans++;
    cout << ans;
}