#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> dunch;

bool comp(pair<int,int> a , pair<int,int> b){
    if(a.first > b.first && a.second > b.second) return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        dunch.push_back(make_pair(x,y));
    }

    for(int i=0; i<n; i++){
        int bigger =1;
        for(int j=0; j<n; j++){
            if(i==j) continue;
            if(comp(dunch[j],dunch[i])) bigger++;
        }
        cout << bigger << " ";
    }

}