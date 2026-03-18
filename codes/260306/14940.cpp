/*
문제
지도가 주어지면 모든 지점에 대해서 목표지점까지의 거리를 구하여라.

문제를 쉽게 만들기 위해 오직 가로와 세로로만 움직일 수 있다고 하자.

입력
지도의 크기 n과 m이 주어진다. n은 세로의 크기, m은 가로의 크기다.(2 ≤ n ≤ 1000, 2 ≤ m ≤ 1000)

다음 n개의 줄에 m개의 숫자가 주어진다. 0은 갈 수 없는 땅이고 1은 갈 수 있는 땅, 2는 목표지점이다. 입력에서 2는 단 한개이다.

출력
각 지점에서 목표지점까지의 거리를 출력한다. 원래 갈 수 없는 땅인 위치는 0을 출력하고, 원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치는 -1을 출력한다.*/

#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    int board[1005][1005];
    int depth[1005][1005] = {};
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin >> board[i][j]; 
            if(board[i][j] == 2) q.push({i,j}); 
        }
    }
    pair<int,int> target = q.front();
    while(!q.empty()){
        pair<int,int> x = q.front(); q.pop();
        pair<int,int> dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto d : dir){
            int i=x.first+d.first, j=x.second+d.second;
            if(i<0||i>=n||j<0||j>=m) continue;
            if(!board[i][j] || depth[i][j]) continue;
            q.push({i,j});
            depth[i][j] =  depth[x.first][x.second]+1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i==target.first&&j==target.second) depth[i][j] = 0;
            else if(!depth[i][j] && board[i][j]) depth[i][j] = -1;
            cout << depth[i][j] << " ";
        }
        cout <<"\n";
    }
}