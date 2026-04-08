#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        int c; cin >> c;
        if(i==0) arr[i] = c;
        else arr[i] = arr[i-1]+c; 
    }
    while(m--){
        int a, b; cin >> a >> b;
        if(a==1) cout << arr[b-1] << "\n";
        else cout << arr[b-1]-arr[a-2] << "\n";
    }
}