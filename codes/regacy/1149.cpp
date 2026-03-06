#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int min[3];
    cin >> min[0] >> min[1] >> min[2];

    for(int i=1; i<n; i++){
        int R,G,B;
        cin >> R >> G >> B;
        int current[3] = {min[0],min[1],min[2]};

        min[0] = (current[1]<current[2]) ? current[1] +R : current[2] +R;
        min[1] = (current[0]<current[2]) ? current[0] +G : current[2] +G;
        min[2] = (current[0]<current[1]) ? current[0] +B : current[1] +B;
    }
    cout << std::min(std::min(min[0],min[1]),min[2]);
}