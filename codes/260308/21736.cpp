/*문제
2020년에 입학한 헌내기 도연이가 있다. 도연이는 비대면 수업 때문에 학교에 가지 못해 학교에 아는 친구가 없었다. 드디어 대면 수업을 하게 된 도연이는 어서 캠퍼스 내의 사람들과 친해지고 싶다. 

도연이가 다니는 대학의 캠퍼스는 
$N \times M$ 크기이며 캠퍼스에서 이동하는 방법은 벽이 아닌 상하좌우로 이동하는 것이다. 예를 들어, 도연이가 (
$x$, 
$y$)에 있다면 이동할 수 있는 곳은 (
$x+1$, 
$y$), (
$x$, 
$y+1$), (
$x-1$, 
$y$), (
$x$, 
$y-1$)이다. 단, 캠퍼스의 밖으로 이동할 수는 없다.

불쌍한 도연이를 위하여 캠퍼스에서 도연이가 만날 수 있는 사람의 수를 출력하는 프로그램을 작성해보자.

입력
첫째 줄에는 캠퍼스의 크기를 나타내는 두 정수 
$N$ (
$ 1 \leq N \leq 600$), 
$M$ (
$ 1 \leq M \leq 600$)이 주어진다.

둘째 줄부터 
$N$개의 줄에는 캠퍼스의 정보들이 주어진다. O는 빈 공간, X는 벽, I는 도연이, P는 사람이다. I가 한 번만 주어짐이 보장된다.

출력
첫째 줄에 도연이가 만날 수 있는 사람의 수를 출력한다. 단, 아무도 만나지 못한 경우 TT를 출력한다.*/

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m; cin >> n >> m;
    char campus[601][601];
    bool visit[601][601] = {};
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++){
            campus[i][j] = s[j];
            if(campus[i][j]=='I') {
                q.push({i,j});
                visit[i][j] = true;
            }
        }
    }
    int ans = 0;
    while(!q.empty()){
        auto x = q.front(); q.pop();
        if(campus[x.first][x.second]=='P') ans++;
        pair<int,int> dir[] = {{1,0},{-1,0},{0,1},{0,-1}};
        for(auto d: dir){
            int y1 = x.first+d.first, y2= x.second+d.second;
            if(y1<0||y1>n-1||y2<0||y2>m-1) continue;
            if(campus[y1][y2]=='X') continue;
            if(visit[y1][y2]) continue;
            q.push({y1,y2});
            visit[y1][y2] = true;
        }
    }
    if(ans==0) cout << "TT";
    else cout << ans;
}