#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; string str;
    cin >> n >> str;
    long long l=0;
    long long mult = 1;
    for(int i=0; i<str.size();i++){
        l+= (str[i]-'a'+1)*mult;
        mult *= 31;
        if(mult > 1234567891) mult %= 1234567891;
        if(l >= 1234567891) l %= 1234567891;
    }
    cout << l;
}