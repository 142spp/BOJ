#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int,int>> vc;
    while(n--){
        int a,b; cin >> a >> b;
        vc.push_back(make_pair(a,b));
    }
    sort(vc.begin(),vc.end(),[](pair<int,int> a,pair<int,int> b){
        if(a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });

    for(auto i : vc){
        cout << i.first << " " << i.second << "\n";
    }
}