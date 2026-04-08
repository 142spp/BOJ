#include <bits/stdc++.h>
using namespace std;

vector<int> parents;

int find(int x){
    if(parents[x]==x) return x;
    return find(parents[x]);
}

void unite(int a, int b){
    int rootA = find(a);
    int rootB = find(b);
    if( rootA != rootB) 
        parents[rootB] = rootA;
}

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    parents.resize(n+1);
    for(int i=1; i<n+1; i++) parents[i] = i;
    while(m--){
        int o , a , b;
        cin >> o >> a >> b;
        if(o==0){
            unite(a,b);
        }else{
            int rootA = find(a);
            int rootB = find(b);
            if(rootA != rootB) cout << "NO";
            else cout << "YES";
            cout << "\n";
        }
    }

}
    