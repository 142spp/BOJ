#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> vc(31);
    for(int i=1; i<=28; i++){
        int s; cin >> s; vc[s]++;
    }
    for(int i=1; i<=30; i++){
        if(!vc[i]) cout << i << "\n";
    }
    return 0;
}