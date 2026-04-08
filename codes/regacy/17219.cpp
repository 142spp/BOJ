#include <bits/stdc++.h>

using namespace std;

map<string,string> dict;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    while(n--){
        string site,pass;
        cin >> site >> pass;
        dict.insert({site,pass});
    }
    while(m--){
        string site;
        cin >> site;
        auto fs = dict.find(site);
        if(fs!=dict.end()) cout << (*fs).second << "\n";
    }
}