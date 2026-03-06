#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>> n;
    while(n--){
        int H,W,N; cin >> H >> W >> N;
        int floor = N%H, room = N/H;
        if(floor == 0){
            floor = H;
            room --;
        }
        printf("%d%02d\n",floor,room+1);
    }
}