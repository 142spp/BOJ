#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,i;
    cin >> n;
    for(i = 0; i<n; i++){
        int temp = i;
        int division = temp;
        while(temp>0){
            division += temp%10;
            temp/=10;
        }
        if(division == n){ cout << i; break;}
    }
    if(i == n) cout << 0;
}