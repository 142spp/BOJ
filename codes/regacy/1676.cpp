#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int twos=0,fives=0;
    for(int i=1; i<=n; i++){
        int j = i;
        while(j%2==0||j%5==0){
            if(j%2==0) {
                twos++;
                j /= 2;
            }
            if(j%5==0) {
                fives++;
                j /= 5;
            }
        }
    }
    cout << min(twos,fives);
}