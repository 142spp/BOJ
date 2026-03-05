#include <iostream>
#include <math.h>

using namespace std;

int is_prime(int num){
    if(num == 1) return 0;
    else if(num == 3) return 1;
    for(int i =2; i<=sqrt(num); i++){
        if(num%i==0) return 0;
    }
    return 1;
}

int main(){
    int num_min , num_max;
    cin >> num_min >> num_max ;
    int sum=0;
    int min = 10000;
    for(int temp=num_min; temp<=num_max; temp++){
        if(is_prime(temp)){
            sum += temp;
            if(temp < min) min = temp;
        }
    }
    if(min == 10000) cout << -1 ;
    else{
        cout << sum <<"\n";
        cout << min;   
    }
}