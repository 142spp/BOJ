#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(NULL);
    int n,t; cin >> n >> t;
    vector<int> vc(n);
    for(auto& x:vc) cin >> x;

    for (int i=0; i<n; i++){
        for (int j=i-1; j>=0; j--){
            if(j==0){

            }
            if(vc[i]>vc[j]){break;}
            
        }
    }

    for(auto x:vc)cout<<x <<" ";
}