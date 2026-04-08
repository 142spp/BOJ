#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vc;
queue<pair<pair<int,int>,int>> q;

vector<pair<int,int>> dv = {{1,0},{-1,0},{0,1},{0,-1}};

int main(){
    int n,m; cin >> n >> m;
    vc.resize(n,vector<int>(m));
    for(int i=0; i<n; i++){
        string numbers;
        cin >> numbers;
        for(int j=0; j<m; j++){
           vc[i][j] = numbers[j]-'0';
        }
    }
    q.push({{0,0},1});
    int visited[101][101]={};
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.first.first, y = cur.first.second;
        if(x == n-1 && y == m-1) {
            cout << cur.second;
            break;
        } 
        for(auto dxy : dv){
            int dx = dxy.first, dy = dxy.second;
            if(x+dx<0||x+dx>n-1||y+dy<0||y+dy>m-1) continue;
            if(vc[x+dx][y+dy] && !visited[x+dx][y+dy]){
                q.push({{x+dx,y+dy},cur.second+1});
                visited[x+dx][y+dy] = 1;
            }
        }
    }
}
