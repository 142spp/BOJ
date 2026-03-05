#include <bits/stdc++.h>

using namespace std;

int main(){
    while(true){
        vector<int> vc(3,0);
        cin >> vc[0] >> vc[1] >> vc[2];
        if(vc[0]==0 && vc[1]==0 && vc[2]==0) break;

        sort(vc.begin(),vc.end());
        if(vc[2]*vc[2]==vc[0]*vc[0] + vc[1]*vc[1] ) cout << "right" <<"\n";
        else cout << "wrong" << "\n";   
    }
    return 0;
}