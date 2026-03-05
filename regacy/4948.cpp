#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    bool numlist [123456*2+1] ={0,};
    for(int i=3; i<=sqrt(123456*2); i+=2){
        for(int j=3; j<=(123456*2)/i; j+=2){
            numlist[i*j] = 1;
        }
    }

    int num;
    while(cin >> num){
        if(num == 0) return 0;
        int sum=0;
        for(int i=num+1; i<=num*2; i++){
            if(i==2||(i%2!=0 && !numlist[i])) {
                sum ++;
            }
        }
        cout << sum << "\n";
    }
}