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
    int num;
    cin >> num;
    int sum=0;
    for(int i=0; i<num; i++){
        int temp;
        cin >> temp;
        sum += is_prime(temp);
    }
    cout << sum <<"\n";
}