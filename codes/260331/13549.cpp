#include <bits/stdc++.h>
using namespace std;


int main(void){
    int n, k; cin >> n >> k;
    int ans[200001] = {};
    bool visited[200001] = {};
    deque<int> dq;
    dq.push_back(n);
    visited[n] = true;
    while(dq.front()!=k){
        auto f = dq.front(); dq.pop_front();
        if(f*2<200001 && !visited[f*2]) {
            dq.push_front(f*2);
            ans[f*2] = ans[f];
            visited[f*2] = true;
        }
        if(f>0 && !visited[f-1]) {
            dq.push_back(f-1);
            ans[f-1] = ans[f] +1;
            visited[f-1] = true;
        }
        if(f<=100000 && !visited[f+1]) {
            dq.push_back(f+1);
            ans[f+1] = ans[f] +1;
            visited[f+1] = true;
        }
    }
    cout << ans[k];
}