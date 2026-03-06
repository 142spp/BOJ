#include <bits/stdc++.h>

#define MAX 500001

using namespace std;

int arr[MAX];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;
    for(int i=0; i< n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int m; cin >> m;
    while(m--){
        int c; cin >> c;
        printf("%ld ",upper_bound(arr,arr+n,c)-lower_bound(arr,arr+n,c));
    }
}
