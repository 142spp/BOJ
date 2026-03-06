#include <iostream>
#include <math.h>

using namespace std;

void min_pirme(int& num){
    if(num % 2 == 0) {
        num/=2;
        cout << 2 << "\n";
        return;
    }

    else if(num % 3 == 0) {
        num/=3;
        cout << 3 << "\n";
        return ;
    }

    for(int i=2; i<=sqrt(num); i++){

        if(num % i == 0){
            num /= i;
            cout << i <<'\n';
            return ;
        }
    }

    cout << num <<'\n';
    num /= num;

}

int main(){

    int num;
    cin >> num;

    while(num!=1){
        min_pirme(num);
    }

}