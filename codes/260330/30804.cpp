#include <bits/stdc++.h>
using namespace std;

// 투포인터 -> 슬라이딩 윈도우

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<int> v(n);
    for(auto& x : v) cin >> x;
    int ans = 0;
    int fruit[10] = {};
    int cnt = 0;
    int l = 0;
    for(int r=0; r<n; r++){
        if(fruit[v[r]]==0) cnt++;
        fruit[v[r]]++;
        while(cnt>2){
            fruit[v[l]]--;
            if(fruit[v[l]]==0) cnt--; 
            l++;
        }
        ans = max(ans,r-l+1); 
    }
    cout << ans;
}