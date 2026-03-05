#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int index = 0 ;
    for(int i=1; i<INT_MAX; i++){
        string str = to_string(i);
        if(str.find("666")!=string::npos) index++;
        if(n == index) {cout << i; break;}
    }
}