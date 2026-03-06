#include <bits/stdc++.h>

using namespace std;

vector<int> prs={};

void make_prs(long long m){
    for(int i=2; i<sqrt(m); i++){
        int j=0;
        for(; j<prs.size(); j++){
            if(i%prs[j]==0) break;
        }
        if(j>=prs.size()-1) prs.push_back(i);
    }
}

bool is_nonsqr(long long i){
    for(int j=0; prs[j]<=sqrt(i); j++){
        if(i%j == 0) return false;
    }
    for(int j=0; j < a; j++)
    return true;
}

int main(){
    long long min, max;
    cin >> min >> max;

    make_prs(max);
    for(auto p : prs){
        cout << p << "\n";
    }
    return 0;

    int ans=0;
    for(long long i = min; i < max; i++){
        if(is_nonsqr(i)){
            ans++;
        }
    }
    cout << ans;
}