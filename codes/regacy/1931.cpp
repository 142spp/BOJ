#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vc;

vector<int> buffer;
stack<pair<int,int>> ans;

void back_track(int s, int e){
    ans.push(make_pair(s,e));
    for(int i = s-1; i< e;){
        if(buffer[i] >= 1){
            ans.pop();
            return ;
        } else {
            buffer[i]++;
        }
    }
    
}

int main(){
    int i; cin >> i;
    while ( i --){
        int x,y; cin >> x >> y;
        vc.push_back(make_pair(x,y));
    }
    buffer.resize(vc.size());
}