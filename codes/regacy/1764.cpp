#include <bits/stdc++.h>

using namespace std;

int main(){
<<<<<<< HEAD
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
=======
>>>>>>> 9253dad4c3abacf60e84042fe790059abb8ae6fb
    int n,m; cin >> n >> m;
    set<string> dl;
    vector<string> bl;
    
    while(n--){
        string s; cin >> s;
        dl.insert(s);
    }
    while(m--){
        string s; cin >> s;
        bl.push_back(s);
    }
    vector<string> ans;
    for(auto s : bl){
        if(dl.find(s)!=dl.end()) ans.push_back(s);     
    }
<<<<<<< HEAD
=======
    sort(ans.begin(),ans.end());
>>>>>>> 9253dad4c3abacf60e84042fe790059abb8ae6fb
    cout << ans.size() << "\n";
    for(auto s : ans) cout << s << "\n";
    return 0;
    
}