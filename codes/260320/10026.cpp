/*문제
적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

예를 들어, 그림이 아래와 같은 경우에

RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)

그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.*/

#include <bits/stdc++.h>
using namespace std;

int bfs(vector<string>& pic){
    int cnt = 0;
    int n = pic.size();
    bool visited[101][101] = {};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j]) continue;
            char color = pic[i][j];
            deque<pair<int,int>> dq;
            dq.push_back({i,j});
            visited[i][j] = true;
            while(!dq.empty()){
                auto f = dq.front();  dq.pop_front();
                pair<int,int> dir[] = {{1,0},{-1,0},{0,1},{0,-1}};
                for(auto d : dir){
                    auto x = f.first + d.first;
                    auto y = f.second + d.second;
                    if(x<0 || x>n-1 || y<0 || y>n-1) continue;
                    if(visited[x][y] || pic[x][y] != color) continue;
                    visited[x][y] = true;
                    dq.push_back({x,y}); 
                }
            }
            cnt++;
        }
    }
    return cnt;
}

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<string> pic;
    vector<string> rg_pic;
    for(int i=0; i<n; i++){
        string s; cin >> s; pic.push_back(s);
    }
    for(auto s : pic){
        for(auto& c: s) {
            if(c=='R') c = 'G';
        }
        rg_pic.push_back(s);
    }
    cout << bfs(pic) << " " << bfs(rg_pic) ;
}