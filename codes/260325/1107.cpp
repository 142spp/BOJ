#include <bits/stdc++.h>
using namespace std;

vector<int> ans, v = {1,2,3,4,5,6,7,8,9,0};
int cnt[1000001] = {};
void dfs(int n){
    for(auto x : v){
        int nxt = n*10+x;
        if(nxt>1000000) continue;
        if(cnt[nxt]) continue;
        ans.push_back(nxt);
        cnt[nxt] = cnt[n]+1;
        dfs(nxt);
    }
}

int main(void){
    int n, m; cin >> n >> m;
    for(int i=0; i<m; i++){
        int c; cin >> c;
        v.erase(find(v.begin(),v.end(),c));
    }
    int min_cnt = abs(n-100);
    ans.push_back(100);
    
    dfs(0);
    //for(auto x : ans) cout << x << "\n";
    for(auto x: ans){
        if(min_cnt > abs(x-n)+cnt[x]) 
            min_cnt = abs(x-n)+cnt[x];
    }
    cout << min_cnt;
}