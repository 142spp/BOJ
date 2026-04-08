#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m; cin >> n;
    vector<int> arr(n);
    for(auto& x: arr) cin >> x;
    sort(arr.begin(),arr.end());
    cin >> m;
    while(m--){
        int c; cin >> c;
        int x=0, y=n-1;
        while(x<y-1){
            int mid = (x+y)/2;
            if(arr[mid]<=c) x = mid;
            else y = mid;
        }
        if (arr[x]==c || arr[y]==c) cout << 1 << "\n";
        else cout << "0" << "\n";
    }    
}