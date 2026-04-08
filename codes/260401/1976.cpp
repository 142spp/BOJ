#include <bits/stdc++.h>
using namespace std;

vector<int> parents;
int find(int x){
    if(parents[x]==x) return x;
    return find(parents[x]);
}
void unite(int a, int b){
    int roota = find(a);
    int rootb = find(b);
    if(roota!=rootb){
        parents[rootb] = roota;
    }
}
int main(void){
    int n, m; cin>> n >> m;
    vector<vector<int>> adj(n,vector<int>(n));
    parents.resize(n+1);
    for(int i=0; i<n+1; i++){
        parents[i] = i;
    }
    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            cin >> adj[i][j];
        }
    }
    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            if(adj[i][j]==1)
                unite(i,j);
        }
    }
    vector<int> travle(m);
    for(auto& x: travle) cin >> x;
    for(int i=1; i<m; i++){
        if(find(travle[i-1]-1)!=find(travle[i]-1)){
            cout<< "NO"; return 0;
        }
    }
    cout <<  "YES";
}
    