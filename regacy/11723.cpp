#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n; cin >> n;
    int S[21] = {};
    while(n--){
        string s; cin>> s;
        if(!s.compare("add")){
            int x; cin >> x;
            S[x] = 1;
        }
        else if(!s.compare("remove")){
            int x; cin >> x;
            S[x] = 0;
        }
        else if(!s.compare("check")){
            int x; cin >> x;
            if(S[x]==1) cout << 1;
            else cout << 0;
            cout << "\n";
        }
        else if(!s.compare("toggle")){
            int x; cin >> x;
            S[x] = !S[x];
        }
        else if(!s.compare("all")){
            for(int i=0; i< 21; i++) S[i] =1;
        }
        else if(!s.compare("empty")){
            for(int i=0; i<21; i++) S[i] = 0;
        }
    }
    return 0;
}