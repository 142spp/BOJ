#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    string ans;
    while(cin >> s){
        if(s.back()==EOF) break;
        ans.append(s);
        if(s.back() != '\n') ans.append(" ");
        else ans.append("\n");
    }
    cout << ans;
    return 0;
}