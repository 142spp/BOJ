#include <bits/stdc++.h>

using namespace std;

int main(){
    string str; cin >> str;
    for(auto ch : str){
        if(ch >= 'A' && ch <= 'Z'){
            cout << (char)(ch - 'A' + 'a');
        }else {
            cout << (char)(ch + 'A' - 'a');
        }
    }
}