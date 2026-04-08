/*문제
대회가 다가오는데도 문제를 만들지 못한 하이비는 결국 AI의 힘을 빌려 다음과 같은 문제를 만들었다.

정수 
$x$, 길이 
$N$의 정수로 이루어진 수열 
$L$과 
$R$에 대해, 다음과 같은 함수 
$f$를 정의해 보자.

f(x, L[1..N], R[1..N]):
    value = x
    for i = 1 to N
        l = L[i]
        r = R[i]
        if l ≤ x ≤ r
           value = value^(((x|l)+(x&r)*(l^r)) mod (2**64))
    return (value >= 0x0123456789ABCDEF)
코드에 적힌 |, &, ^, **, 0x, mod연산에 대해서는 노트를 참고하자.

 
$L$과 
$R$이 주어질 때, 
$f(x,L,R) =\text{False}$이면서 
$f(x+1,L,R) =\text{True}$인 
$x$를 찾으면 된다.

하지만 AI가 만들어 준 이 문제가 너무 어려웠던 하이비는 이 문제를 풀지도 못한 채로 내야 할 위기에 처하게 되었다! 하이비를 위해 위 문제의 답을 찾아주자.

입력
첫 번째 줄에는 수열의 길이 
$N$이 주어진다. 
$(1\le N\le 200\, 000)$ 

두 번째 줄에는 수열 
$L_1,L_2,\ldots ,L_N$이 공백으로 구분되어 주어진다.

세 번째 줄에는 수열 
$R_1,R_2,\ldots ,R_N$이 공백으로 구분되어 주어진다. 
$(1\le L_i\le R_i\le 10^{18})$ 

출력
첫 번째 줄에 문제의 답으로 가능한 
$x$의 값을 출력한다. 
$(0\le x\le 10^{18})$ 

만약 가능한 답이 여러 가지라면, 그중 아무거나 하나를 출력한다.

만약 가능한 답이 없다면, 
$-1$을 출력한다.*/

#include <bits/stdc++.h>
using namespace std;

bool func(uint64_t x, vector<uint64_t>& L, vector<uint64_t>& R){
    uint64_t val = x;
    for(int i=0; i<L.size(); i++){
        if(L[i]<=x && x<=R[i]) {
            val = val ^ ((x|L[i]) + (x&R[i]) * (L[i]^R[i]))  ; 
        }
    }
    return val>=0x0123456789ABCDEF;
}

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >>n;
    vector<uint64_t> L(n);
    for(auto& x:L) cin >> x;
    vector<uint64_t> R(n);
    for(auto& y:R) cin >> y;

    uint64_t x_l = 0, x_r = (uint64_t)pow(10,18);
    uint64_t x;
    while(x_l<=x_r){
        x = (x_l+x_r)/2;
        bool lc = func(x,L,R);
        bool rc = func(x+1,L,R);
        if(!lc&&rc) {
            cout << x ;
            return 0;
        }
        if(lc&&rc) x_r = x;
        else x_l = x+1;
    }
    cout << -1;
    return 0;
}