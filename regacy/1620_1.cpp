#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    map<string,int> m1;
    map<int,string> m2;
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s; cin >> s;
        m1.insert(make_pair(s,i));
        m2.insert(make_pair(i,s));
    }
    while(m--){
        string s; cin >> s;
        if(s[0] >= '0' && s[0]<='9'){
            cout << m2.find(stoi(s))->second;
        }else{
            cout << m1.find(s)->second;
        }
        cout << "\n";
    }
}