#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a, b; cin >> a >> b;
    priority_queue<long long,vector<long long>, greater<>> q;
    q.push(a);
    map<long long,int> m;
    while(q.top()!=b){
        long long f = q.top(); q.pop();
        if(f>b) break;
        if(m[f*2]>0) continue;
        else {
            m[f*2] = m[f]+1; 
            q.push(f*2);
        }
        if(m[f*10+1]>0) continue;
        else{
            m[f*10+1] = m[f]+1;
            q.push(f*10+1);
        }
    }
    if(m[b]==0) cout << -1;
    else cout << m[b]+1;
}