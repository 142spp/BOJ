#include <bits/stdc++.h>

using namespace std;

int main(){
    string str; cin >> str;
    vector<int> num;
    int sum = 0;
    int flag = 1;
    for(int j=0; j<=str.size(); j++){
        char ch = str[j];
        if(ch=='+' || ch=='-' || ch == '\0'){
            for(auto n : num) sum += n*flag;
            num.clear();
            if(ch=='-') flag = -1;
        }
        else {
            for(int i=0; i<num.size(); i++) num[i]*= 10;
            num.push_back(ch-'0');
        }
    }
    cout << sum ;
}