#include <bits/stdc++.h>
using namespace std;

bool visited[9] = {};
vector<int> arr;
int n,m ;

void dfs(){
    if((int)arr.size()==m){
        for(auto x : arr) cout << x << " ";
        cout << "\n";
        return;
    }
    int last = arr.empty() ? 1 : arr.back()+1;
    for(int i=last; i<=n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        arr.push_back(i);
        dfs();
        arr.pop_back();
        visited[i] = false;
    }
}

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    dfs();
}