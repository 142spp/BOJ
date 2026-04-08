#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m; cin >> n >>m;
    int tn; cin >> tn;
    bool truth[51] = {};
    for(int i=0; i<tn; i++){
        int x; cin >> x;
        truth[x] = true;
    };
    vector<vector<int>> p;
    for(int i=0; i<m; i++){
        int c; cin >> c;
        vector<int> s(c);
        for(auto& x: s ) cin>> x;
        p.push_back(s);
    }
    for(int i=0; i<m+1; i++){
        for(int j=0; j<m; j++){
            bool t_flag = false;
            for(auto x : p[j]){
                if(!truth[x]) continue;
                t_flag = true; break;
            }
            if(t_flag){
                for(auto x : p[j])
                    truth[x] = true;
            }
        }
    }
    int ans = 0;
    for(int i=0; i<m; i++){
        if(truth[p[i][0]]==false) ans++;
    }
    cout << ans;
}
    