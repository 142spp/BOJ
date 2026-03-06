#include <bits/stdc++.h>

using namespace std;

void loop(string::iterator &st, string::iterator &ed){
    while(st!=ed){
        if(*st != *ed) break;
        if(++st == ed--) {ed++; break;}
    }
}

int palin(string str){
    string::iterator st = str.begin(), ed = --str.end(); 
    loop(st,ed);
    if(st==ed) return 0;
    
    string::iterator t_st, t_ed;
    
    t_st = st + 1, t_ed = ed;
    loop(t_st,t_ed);
    if(t_st==t_ed) return 1;
    
    t_st= st, t_ed = ed - 1;
    loop(t_st,t_ed);
    if(t_st==t_ed) return 1;
    
    return 2;
}

void init(){
    int n; cin >> n;
    while(n--){
        string str;
        cin >> str;
        cout << palin(str) << "\n";
    }
}

int main(){
    init();
    return 0;
}