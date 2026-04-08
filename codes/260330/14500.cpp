#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<vector<int>> v;
pair<int,int> dir[] = {{1,0},{-1,0},{0,1},{0,-1}};
int visited[501][501] = {};

void dfs(int depth, int sum, int x, int y){
    if(depth == 4) { 
        ans = max(ans,sum); return; }
    for(auto d: dir){
        int nx = x + d.first;
        int ny = y + d.second;
        if(nx<0||nx>v.size()-1||ny<0||ny>v[0].size()-1) continue;
        if(visited[nx][ny]>0) continue;
        visited[nx][ny] ++;
        dfs(depth+1,sum+v[nx][ny],nx,ny);
        visited[nx][ny] --;
    }

}

int main(void){
    int n, m; cin >> n >> m;
    v.resize(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> v[i][j];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            visited[i][j]++;
            dfs(1,v[i][j],i,j);
            visited[i][j]--;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int x = 0; x<4; x++){
                int cnt = 0;
                int sum = v[i][j];
                for(auto d : dir){
                    if(dir[x] == d) continue;
                    int ni = i+d.first;
                    int nj = j+d.second;
                    if(ni<0||ni>v.size()-1||nj<0||nj>v[0].size()-1) continue;
                    cnt ++; sum+= v[ni][nj];
                }
                if(cnt != 3) continue;
                ans = max(ans,sum);
            }
            
        }
    }
    cout << ans;
}