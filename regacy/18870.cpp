#include <bits/stdc++.h>

using namespace std;

int j;
vector<int> vc;

vector<pair<int,int>> pr;
int binary_search(int i){
    int s = 0, e = pr.size()-1;
    int m;
    while(s<=e){
        m = (s+e) /2;
        if(pr[m].first==i) break;
        if(pr[m].first > i) e = m-1;
        else s = m+1;
    }
    return pr[m].second;
}

int main(){
    int n; cin >> n;
    while(n--){
        int s; cin >> s;
        vc.push_back(s);
    }
    vector<int> cp(vc);
    sort(cp.begin(),cp.end());
    int count = 0; pr.push_back(make_pair(cp[0],count++));
    for(int i=1; i<cp.size(); i++){
        if(cp[i-1] != cp[i]) 
            pr.push_back(make_pair(cp[i],count++));
    }
    for(j=0;j< vc.size();j++){
        cout << binary_search(vc[j]) << " ";
    }
}