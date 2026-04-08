#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vc(n);
    for(int i=0; i<vc.size(); i++) cin >> vc[i];
    int m; cin >> m;
    int count = 0;
    for(int i=0; i<vc.size(); i++) if(vc[i] == m) count++;
    cout << count;
    return 0;
}