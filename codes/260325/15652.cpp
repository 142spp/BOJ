#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> arr;

void dfs(){
    if(arr.size() == m){
        for(auto x : arr){
            cout << x << " ";
        } cout << "\n";
        return;
    }
    int last = arr.empty() ? 1 : arr.back();
    for(int i= last; i<=n; i++){
        arr.push_back(i);
        dfs();
        arr.pop_back();
    }
}

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    dfs();
}