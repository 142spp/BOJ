#include <bits/stdc++.h>
using namespace std;

int opers[4];
vector<int> v;
vector<int> ans;
void dfs(int n){
    if(v.empty()) ans.push_back(n);
    for(int i=0; i<4; i++){
        if(!opers[i]) continue;
        opers[i]--;
        int b = v.back(); v.pop_back();
        if(i==0)dfs(n+b);
        if(i==1)dfs(n-b);
        if(i==2)dfs(n*b);
        if(i==3)dfs(n/b);
        v.push_back(b);
        opers[i]++;
    }
}

int main(void){
    cin.tie(nullptr);
    
    int n; cin >> n;
    v.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(auto& o : opers){
        cin >> o;
    }
    reverse(v.begin(),v.end());
    int init = v.back(); v.pop_back();
    dfs(init);
    cout << *max_element(ans.begin(),ans.end())\
    << "\n" << *min_element(ans.begin(),ans.end());
}