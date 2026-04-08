#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n+1);
        for(int i=1;i<=n;i++){
            cin >> arr[i];
        }
        vector<int> sarr(n);
        sarr[0] = arr[0];
        for(int i=1; i<=n; i++){
            sarr[i] = sarr[i-1] + arr[i];
        }
    }
}


/*
2 1 -2 3 -5

*/