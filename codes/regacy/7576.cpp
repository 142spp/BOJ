#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vc;
queue<pair<int,int>> q;

int main(){
    int n,m; cin >> n >> m;
    vc.resize(m,vector<int>(n,0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> vc[i][j] ;
        }
    }
    for(int i=0;i<vc.size();i++){
        for(int j=0;j<vc[i].size();j++){
            if(vc[i][j]==1) q.push(make_pair(i,j));
        }
    }
    int real_count = 0;
    while(!q.empty()){
        real_count++;
        int count = q.size();
        while(count--){
            pair<int,int> t = q.front(); q.pop();
            int tf = t.first, ts = t.second;
            if(vc[tf][ts]<0 || vc[tf][ts]>1) continue;

            vc[tf][ts] = 2;
            
            if(tf>0){
                q.push(make_pair(tf-1,ts));
            }
            if(tf<vc.size()-1){
                q.push(make_pair(tf+1,ts));
            }
            if(ts>0){
                q.push(make_pair(tf,ts-1));
            }
            if(ts<vc[0].size()-1){
                q.push(make_pair(tf,ts+1));
            }
        }
    }
    for(auto i:vc){
        for(auto j : i){
            if(j == 0) {
                cout << -1; return 0;
            }
        }
    }
    cout << real_count-2;
    return 0;
}