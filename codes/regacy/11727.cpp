#include <bits/stdc++.h>

using namespace std;

int bp[1001] = {0,1,3,0,};

int main(){
    int n; cin >> n;
    for(int i=3; i<=n; i++){
        bp[i] += bp[i-2]*2 + bp[i-1];
        bp[i] %= 10007;
    }
    cout << bp[n];
}
