#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, m; cin >> n >> m;
    vector<int> vip(m);
    for(auto& v: vip) cin >> v;
    vector<long long> fibo(n+3);
    fibo[0] =1; fibo[1] =1 ; fibo[2] =2;
    for(int i=3; i<=n; i++) fibo[i] = fibo[i-1] + fibo[i-2];
    sort(vip.begin(),vip.end());
    int pre = 0;
    long long ans = 1;
    for(auto v: vip){
        ans *= fibo[v-pre-1];
        pre = v;
    }
    if(vip.empty()) ans = fibo[n];
    else if(vip.back()!=n) ans*=fibo[n-vip.back()]; 
    cout << ans;
}

/*
1
1
12
21
2
123
213
132
3
1234
1324
2134
1243
2143
5
12345
21345
13245
12435
12354
13254
21435
21354
8
*/