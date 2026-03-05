#include <iostream>
#include <math.h>

using namespace std;

bool is_prime(int num){
    if(num == 1) return 0;
    if(num == 2) return 1;
    if(num == 3) return 1;

    for(int i=2; i<=sqrt(num); i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int min, max;
    cin >> min >> max;

    for(int i=min; i<=max; i++ ){
        if(is_prime(i)) cout << i << "\n";
    }
}