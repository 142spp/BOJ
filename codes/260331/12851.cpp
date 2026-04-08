#include <bits/stdc++.h>
using namespace std;


int main(void){
    int n, k; cin >> n >> k;
    int ans[200001] = {};
    deque<int> dq;
    dq.push_back(n);
    while(dq.front()!=k){
        auto f = dq.front(); dq.pop_front();
        if(f>0) {
            dq.push_back(f-1);
            ans[f-1] = ans[f] +1;
        }
        if(f<=100000) {
            dq.push_back(f+1);
            ans[f+1] = ans[f] +1;
        }
        if(f*2<200001) {
            dq.push_back(f*2);
            ans[f*2] = ans[f] +1;
        }
    }
    int cnt = 0;
    while(!dq.empty()){
        if(dq.front()==k) cnt++;
        dq.pop_front();
    }
    cout << ans[k] << "\n" << cnt;
}