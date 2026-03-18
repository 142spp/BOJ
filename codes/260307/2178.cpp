/*문제
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.*/

#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int board[105][105] = {};
    for(int i=0;i<n;i++){
        string s; cin >> s;
        for(int j=0; j<m;j++){
            board[i][j] = s[j]-'0';
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    board[0][0] = 2;
    while(!q.empty()){
        pair<int,int> x = q.front(); q.pop();
        pair<int,int> dir[4] = {{1,0},{-1,0},{0,1},{0,-1}};
        for(pair<int,int> d : dir){
            int y1 = x.first+d.first,  y2 = x.second+d.second;
            if(y1<0||y1>n-1||y2<0||y2>m-1) continue;
            if(!board[y1][y2] || board[y1][y2]>1) continue;
            q.push({y1,y2});
            board[y1][y2] = board[x.first][x.second] +1;
        }
    }
    cout << board[n-1][m-1]-1;
}