#include <bits/stdc++.h>

using namespace std;

string s; 

int main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,string>> vc;
    for(int i=1; i<=n;i++){
        cin >> s;
        vc.push_back(make_pair(i,s));
    }
    while(m--){
        cin >> s;
        if(s.size() < 2) {
            vector<pair<int,string>>::iterator f = find_if(vc.begin(),vc.end(),[](pair<int,string> a){
                if(a.first == s[0]-'0') return true;
                else return false;
            });
            cout << f->second;
        }
        else{
            vector<pair<int,string>>::iterator f = find_if(vc.begin(),vc.end(),[](pair<int,string> a){
                if(a.second.compare(s) ==0) return true;
                else return false;
            });
            cout << f->first;
        }
        cout << "\n";
    }
}