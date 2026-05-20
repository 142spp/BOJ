#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,d ; cin >> n >> d;
    int ans = 0;
    vector<pair<int,int>> A(n);
    vector<pair<int,int>> B(n);
    for(int i=0; i<n; i++){
        int t,a,b; cin >> t >> a >> b;
        A[i].first = t; A[i].second = a;
        B[i].first = t; B[i].second = b;
        ans = max(ans,a+b);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater());
    for(int i=n-2; i>=0; i--){
        if(B[i+1].second>B[i].second) B[i].second = B[i+1].second;
    }
    int idx_b = 0;
    for(int idx_a=0; idx_a<n; idx_a++){
        int cur_t = d - A[idx_a].first;
        while(B[idx_b].first > cur_t){
            idx_b++;
        }
        ans = max(ans,A[idx_a].second + B[idx_b].second);
    }
    cout << ans;
}