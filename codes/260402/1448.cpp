#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<int> v(n);
    for(auto& x: v) cin >>x;
    sort(v.begin(),v.end(),greater());
    int ans = -1;
    for(int i=0; i<n-2;i++){
        if(v[i]+v[i+1]+v[i+2]>2*max({v[i],v[i+1],v[i+2]})){
            ans = v[i]+v[i+1]+v[i+2];
            break;}
    }
    cout << ans;
}