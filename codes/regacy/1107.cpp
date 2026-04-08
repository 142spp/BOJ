#include <bits/stdc++.h>

using namespace std;

vector<int> brok;

int check(int n){
    int c = 0;
    while(true){
        int m = n%10;
        for(int i : brok) if(i==m) return false;
        n /= 10;
        c++;
        if(n<=0) break;
    }
    return c;
}

int main(){
    int n,b; cin >> n >> b;
    brok.resize(b);
    for(int i=0; i<b; i++) cin >> brok[i];
    int count = INT_MAX;
    for(int i=0; i<INT_MAX; i++){
        int cp = check(n+i);
        if(cp) count = cp + i;
        int cm = false;
        if(n-i >= 0){
            cm = check(n-i);
            if(cm) count = cm + i;
        }
        if(cp||cm||i>abs(100-n)) break;
    }
    cout << min(abs(100-n),count);
}