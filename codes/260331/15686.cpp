#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v[2];
int ans = INT_MAX;

void dfs(vector<pair<int,int>>& picked, int idx, int size){
    if(picked.size()==size){
        int sum = 0;
        for(auto x : v[0]){
            int min_dist = INT_MAX;
            for(auto p : picked){
                min_dist = min(min_dist,abs(p.first-x.first)+\
                            abs(p.second-x.second));
            }
            sum += min_dist;
        }
        ans = min(ans,sum);
        return;
    }
    if(idx>v[1].size()-1) return;
    picked.push_back(v[1][idx]);
    dfs(picked,idx+1,size);
    picked.pop_back();
    dfs(picked,idx+1,size);
}

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int c; cin >> c;
            if(c==0) continue;
            v[c-1].push_back({i,j});
        }
    }
    vector<pair<int,int>> a;
    dfs(a,0,m);
    cout << ans;
}