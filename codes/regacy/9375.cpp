#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        map<string,int> closet;
        while(n--){
            string wear,type;
            cin >> wear >> type;
            auto cur = closet.find(type);
            if(cur==closet.end())
                closet.insert({type,1});
            else (*cur).second++;
        }
        int mult = 1;
        for(auto iter:closet){
            mult *= (iter.second + 1);
        }
        cout << mult-1 << "\n";
    }
}