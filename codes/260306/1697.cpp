/*
문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n,k;  cin >> n >> k;
    vector<int> visited(500001,0);
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while(!q.empty()){
        int x = q.front(); q.pop();
        if(x==k) break;
        vector<int> d = {-1,+1,x};
        for(int c : d) {
            int y = x+c;
            if (visited[y]) continue;
            if(c==x && y>k*2) continue;
            q.push(y);
            visited[y] = visited[x]+1;
        }
    }
    cout << visited[k]-1 ;
}