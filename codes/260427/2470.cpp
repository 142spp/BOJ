#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    int idx_a = 0;
    int idx_b = n-1;
    int min_attr = INT_MAX;
    pair<int,int> ans;
    while(idx_a<idx_b){
        int cur_attr = idx_b - idx_a;
        if(min_attr > cur_attr){
            min_attr = cur_attr;
            ans = {v[idx_a],v[idx_b]};
        }
    }   
    cout << ans.first << ans.second;
}