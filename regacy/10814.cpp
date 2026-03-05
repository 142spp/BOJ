#include <bits/stdc++.h>

using namespace std;

struct ss{
    int first;
    string second;
    int id;
    ss(int a, string b, int c) : first(a),second(b),id(c){}
};

int main(){
    int n; cin >> n; int id= 0;
    vector<ss> vc;
    while(n--){
        int m; string st;
        cin >> m >> st;
        vc.push_back(ss(m,st,id++));
    }
    sort(vc.begin(),vc.end(),[](ss a, ss b){
        if(a.first != b.first) return a.first < b.first;
        return a.id < b.id;
    });

    for(auto i : vc){
        cout << i.first << " " << i.second << "\n";
    }
}