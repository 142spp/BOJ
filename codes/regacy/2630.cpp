#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> vc;
vector<vector<int>> table;

int dp(int i, int j){
    if(i<0 || j<0 || i>=vc.size() || j>=vc.size()) return 0;
    if(table[i][j]>0) return table[i][j];
    // excute
    int r = vc[i][j];
    if(dp(i-1,j)>0 && dp(i,j-1)>0 && dp(i-1,j-1)>0) {
        r = min(dp(i-1,j),dp(i,j-1))+1;
    }
    
    table[i][j] = r;
    return r;
}

int main(){
    int n; cin >> n;
    vc.resize(n,vector<int>(n));
    table.resize(n,vector<int>(n,-1));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> vc[i][j];
        }    
    }

    dp(n-1,n-1);
    int max = 0;
    for(auto i : table){
        for(auto j : i){
            if(j>max) max =j;
        }
    }
    cout << max;
    return 0;
}