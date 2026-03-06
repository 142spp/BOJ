#include <bits/stdc++.h>

using namespace std;

bool comp(string a, string b){
    if(a.size() != b.size()) return a.size()< b.size();
    return a<b;
}

int main(){
    vector<string> strings;

    int n; cin >> n;
    while(n--){
        string str;
        cin >> str;
        strings.push_back(str);
    }
    sort(strings.begin(),strings.end(),comp);

    for(int i = 0; i<strings.size(); i++){
        if( i!=0&& strings[i].compare(strings[i-1]) == 0)
            continue;
        cout << strings[i] << "\n";
    }
}