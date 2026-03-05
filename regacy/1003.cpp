#include <iostream>

using namespace std;

int num_of_zero [41] = {1,0,1,1,2,3,};
int num_of_one [41] = {0,1,1,2,3,5,};
/*
int zero=0;
int one =0;
int fibonacci(int n) {
    if(num_of_zero[n]!=0&&num_of_one[n!=0]){
        zero += num_of_zero[n];
        one += num_of_one[n];
        return 0;
    }
    else {

        return fibonacci(n-1) + fibonacci(n-2);
    }
}
*/
int main(){
    int num;
    cin >> num;

    for(int i=0; i<39; i++){
        num_of_zero[i+2] = num_of_zero[i+1]+num_of_zero[i];
        num_of_one[i+2] = num_of_one[i+1]+num_of_one[i];
    }

    for(int i=0; i<num; i++){
        //zero=0;
        //one=0;
        int index;
        cin >> index;
        //fibonacci(index);
        cout << num_of_zero[index] <<" " << num_of_one[index] << endl;
    }
}
