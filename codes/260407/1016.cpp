#include <bits/stdc++.h>
using namespace std;

// 1 <= a <= 1,000,000,000,000
// a < b <= a+ 1,000,000

// a <= k <= b , (k는 제곱수로 나누어지지 않는 수)
// 를 만족하는 k의 개수
// 제곱수로 나누어 지지 않는다 -> 2~sqrt(10^12) = 10^6 까지의 수를 제곱한 수와 나누어 떨어지지 않는다.
// 2~10^6을 모두 조사할 필요 없이, 소수의 제곱수들만 보면 됨
// ex) 10^2 = 2^2*5^2
// 2~10^6의 소수 개수 ~ x/ln(x) ~ 10^6/(6*2) ~ 10^5

int main(void){
    long long a, b; cin >> a >> b;
    bool isprime[1000001] = {};
    fill(isprime,isprime+1000000,true);
    for(int i=2; i<=pow(10,6); i++){
        if(isprime[i]){
            for(int j=2; i*j<=pow(10,6); j++){
                isprime[i*j] = false;
            }
        }
    }
    int ans = b-a+1;
    for(long long i=a; i<=b; i++){
        for(long long j=2; j*j<=i; j++){
            if(isprime[j]){
                if(i%(j*j)==0) { ans --; break; }
            }
        }
    }
    cout << ans;
}