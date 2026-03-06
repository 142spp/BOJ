#include <iostream>

using namespace std;

int sugar(int num_input){
    int num = num_input;
    for(int i = 0 ; num>0 ; i++){
        if(num%5 == 0){
            return (num/5 + i);
        }
        num -= 3;
    }
    if(num_input%3 == 0) return num_input/3;
    return -1;
}

int main(){
    int num;
    cin >> num;
    cout << sugar(num);
}