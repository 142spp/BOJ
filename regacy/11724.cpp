#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vc;
vector<int> ch;

void dfs(int i){
    if(ch[i]==1) return;
    ch[i] = 1;
    for(int j : vc[i]){
        dfs(j);
    }
}

int main(){
    int n,m; cin >> n >> m;
    ch.resize(n+1,0);
    vc.resize(n+1);
    while(m--){
        int i,j; cin >> i >> j;
        vc[i].push_back(j);
        vc[j].push_back(i);
    }
    int count = 0;
    for(int i=1; i<ch.size(); i++){
        if(ch[i]==0){
            dfs(i);
            count ++;
        }
    }
    cout << count;
    return 0;
}