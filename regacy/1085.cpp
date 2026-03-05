#include <bits/stdc++.h>

using namespace std;

int main(){
    int x,y,w,h;
    cin >> x >>y >> w >>h;

    int arr[4] = {x,y,w-x,h-y};
    int smallest = 1000;
    for(int i : arr){
        if(i < smallest) smallest = i;
    }
    cout << smallest;
}