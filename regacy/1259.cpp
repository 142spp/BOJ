#include <bits/stdc++.h>

using namespace std;

bool is_palin(string str) {
    string::iterator st = str.begin();
    string::iterator bk = --str.end();
    while (st != bk) {
        if (*st != *bk) return false;
        if (++st == bk--) break;
    }
    return true;
}

string decide_val(string str) {
    if (is_palin(str)) return "yes";
    else return "no";
}

void exec() {
    while(true){
        string str;
        cin >> str;
        if(!str.compare("0")) break;
        cout << decide_val(str) << endl;
    }
}

int main() {
    exec();
    return 0;
}