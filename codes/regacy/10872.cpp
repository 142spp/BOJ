#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int pact = 1;
    for(int i=2; i<=n; i++) pact *= i;

    cout << pact;
}