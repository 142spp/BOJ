/*문제
팀 레드시프트는 대회 준비를 하다가 지루해져서 샌드박스 게임인 ‘마인크래프트’를 켰다. 마인크래프트는 1 × 1 × 1(세로, 가로, 높이) 크기의 블록들로 이루어진 3차원 세계에서 자유롭게 땅을 파거나 집을 지을 수 있는 게임이다.

목재를 충분히 모은 lvalue는 집을 짓기로 하였다. 하지만 고르지 않은 땅에는 집을 지을 수 없기 때문에 땅의 높이를 모두 동일하게 만드는 ‘땅 고르기’ 작업을 해야 한다.

lvalue는 세로 N, 가로 M 크기의 집터를 골랐다. 집터 맨 왼쪽 위의 좌표는 (0, 0)이다. 우리의 목적은 이 집터 내의 땅의 높이를 일정하게 바꾸는 것이다. 우리는 다음과 같은 두 종류의 작업을 할 수 있다.

좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는다.
인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는다.
1번 작업은 2초가 걸리며, 2번 작업은 1초가 걸린다. 밤에는 무서운 몬스터들이 나오기 때문에 최대한 빨리 땅 고르기 작업을 마쳐야 한다. ‘땅 고르기’ 작업에 걸리는 최소 시간과 그 경우 땅의 높이를 출력하시오.

단, 집터 아래에 동굴 등 빈 공간은 존재하지 않으며, 집터 바깥에서 블록을 가져올 수 없다. 또한, 작업을 시작할 때 인벤토리에는 B개의 블록이 들어 있다. 땅의 높이는 256블록을 초과할 수 없으며, 음수가 될 수 없다.

입력
첫째 줄에 N, M, B가 주어진다. (1 ≤ M, N ≤ 500, 0 ≤ B ≤ 6.4 × 107)

둘째 줄부터 N개의 줄에 각각 M개의 정수로 땅의 높이가 주어진다. (i + 2)번째 줄의 (j + 1)번째 수는 좌표 (i, j)에서의 땅의 높이를 나타낸다. 땅의 높이는 256보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 땅을 고르는 데 걸리는 시간과 땅의 높이를 출력하시오. 답이 여러 개 있다면 그중에서 땅의 높이가 가장 높은 것을 출력하시오.*/

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,m,b; cin >> n >> m >> b;
    map<int,int,greater<int>> ground;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int c; cin >> c;
            ground[c]++;
        }
    }
    vector<pair<int,int>> ans_q = {{INT_MAX,0}};
    for(int i=0; i<=256; i++){
        int t_b =b, t_sum = 0;
        bool skip_flag = false;
        for(auto x: ground){
            if(x.first <= i){
                t_sum += (i-x.first)*x.second;
                t_b -= (i-x.first)*x.second;
                if(t_b<0){ skip_flag = true; break; }    
            }else{
                t_sum += (x.first-i)*x.second*2;
                t_b += (x.first-i)*x.second;
            }
        }
        if(skip_flag) continue;
        if(t_sum<=ans_q.front().first) {
            if(t_sum<ans_q.front().first) ans_q.clear();
            ans_q.push_back({t_sum,i});
        }
    }
    sort(ans_q.begin(),ans_q.end(),[](pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    });
    cout << ans_q.front().first << " " << ans_q.front().second;
}

int main_(void){
    int n,m,b; cin >> n >> m >> b;
    map<int,int,greater<int>> ground;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int c; cin >> c;
            ground[c]++;
        }
    }
    int min_len = 0, max_len = 256;
    int ans_t = INT_MAX, ans_h = 0;
    while(min_len<=max_len){
        int mid_len = (min_len+max_len)/2;
        int sum_t = 0, tb=b;
        for(auto x : ground){
            if(mid_len >= x.first) {
                for(int i=0;i<x.second;i++){
                    if(tb<=0) continue;
                    sum_t += min((mid_len-x.first)*x.second,tb);
                    tb -= min((mid_len-x.first)*x.second,tb);
                }
            }else{
                sum_t += (x.first-mid_len)*x.second*2;
                tb += (x.first-mid_len)*x.second;
            }
        }
        if(sum_t<=ans_t){
            max_len = mid_len-1;
            ans_t = sum_t;
            ans_h = mid_len;
        }else{
            min_len = mid_len+1;
        }
    }
    cout << ans_t << " " << ans_h;
}