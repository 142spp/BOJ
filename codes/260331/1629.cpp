#include <bits/stdc++.h>
using namespace std;

uint64_t C;
uint64_t solve(uint64_t a, uint64_t b){
    if(b==1) return a%C;
    
    uint64_t half = solve(a,b/2);
    if(b%2 == 0) return (half*half)%C;
    else return (half*half)%C*a%C;
}

int main(void){
    uint64_t a,b; cin >> a >> b >> C;
    cout << solve(a,b);    
}