#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int num;
    cin >> num;

    int numlist [10001]={0,};
    int max =0;

    for(int i=0; i<num; i++){
        int input;
        cin >> input;

        if(max < input) max = input;

        numlist[input]++;
    }

    for(int i=0; i<=max; i++){
        if(numlist[i]!=0){
            for(int j=0; j<numlist[i]; j++){
                cout << i << "\n";
            }
        }
    }
}