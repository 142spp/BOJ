#include <bits/stdc++.h>

using namespace std;

int main(){
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
    sort(ans.begin(),ans.end());
    cout << ans.size() << "\n";
    for(auto s : ans) cout << s << "\n";
    return 0;
    
}