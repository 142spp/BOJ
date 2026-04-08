#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a1,a2,b1,b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int a = a1*b2 + a2*b1, b=a2*b2;
    int c = gcd(a,b);
    cout << a/c << " " << b/c;
}