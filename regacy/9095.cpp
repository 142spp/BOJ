#include <bits/stdc++.h>

using namespace std;

vector<int> vc(12,0);

int dp(int m){
    if(vc[m]>0) return vc[m];
    if(m==1) return 1;
    if(m==2) return 2;
    if(m==3) return 4;
    vc[m] = dp(m-3) + dp(m-2) + dp(m-1);
    return vc[m];
}

int main(){
    int n; cin >> n;
    while(n--){
        int m; cin >> m ;
        cout << dp(m)<< "\n";
    }
}