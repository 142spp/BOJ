#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> vc;
vector<vector<int>> ans;

int visited[101] = {};
bool flag = false;
void dfs(int i, int j){
    if(flag||visited[i]) return;
    visited[i] = true;
    for(int k=0; k<ans[i].size(); k++){
        if(ans[i][k]) {
            if(k == j) {
                flag = true;
                return;
            }
            dfs(k,j);
        }
    }
}

int main(){
    int n; cin >> n;
    vc.resize(n,vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> vc[i][j];
        }
    }
    ans = vc;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            memset(visited,false,sizeof(visited)); flag = false;
            dfs(i,j); ans[i][j] = flag;
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}