#include <bits/stdc++.h>

using namespace std;

int main(void){
    int n, t;
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cin >> n >> t;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(),arr.begin()+t);
    for(auto i : arr) cout << i << " ";
    
}