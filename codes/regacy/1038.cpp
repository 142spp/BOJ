#include <bits/stdc++.h>

using namespace std;

int is_descent(long long n){
    int max = -1;
    int zero_flag = 0;
    if(n%10 == 0) zero_flag=1;
    for(;n>0;){
        int cur = n%10;
        if (max >= cur) return 0;
        max = cur;
        n /= 10;
    }
    return 1;
}

int main(){
    int number;
    cin >> number;
    int m  = 0;
    for(long long i=0; i<=9876543210; i++){
        if(m == number){
            cout << i;
            break;
        }
        if(is_descent(i)) m++;
    }
    return 0;
}