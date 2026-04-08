#include <bits/stdc++.h>
using namespace std;

vector<char> lefts(26,'.');
vector<char> rights(26,'.');

void dfs(char ch, int c){
    if(ch == '.') return;
    if(c==0){
        cout << ch;
        dfs(lefts[ch-'A'],0);
        dfs(rights[ch-'A'],0);
    }
    if(c==1){
        dfs(lefts[ch-'A'],1);
        cout << ch;
        dfs(rights[ch-'A'],1);
    }
    if(c==2){
        dfs(lefts[ch-'A'],2);
        dfs(rights[ch-'A'],2);
        cout << ch;
    }
}

int main(void){
    int n; cin >> n;

    for(int i=0; i<n; i++){
        char v,l,r; cin >> v >> l >> r;
        if(l!='.') lefts[v-'A'] = l;
        if(r!='.') rights[v-'A'] = r;
    }   

    dfs('A',0); cout << "\n";
    dfs('A',1); cout << "\n";
    dfs('A',2);
}