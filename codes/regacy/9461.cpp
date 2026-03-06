#include <iostream>

using namespace std;

int main(){
    unsigned long long int* p = new unsigned long long int[1000];
    p[1]=1;
    p[2]=1;
    p[3]=1;
    p[4]=2;
    p[5]=2;
    p[6]=3;
    p[7]=4;
    p[8]=5;
    p[9]=7;
    p[10]=9;

    for(int i = 11; i<1000; i++){
        p[i]=p[i-1] + p[i-5];
    }

    int test;
    cin >> test;
    for(int i = 0 ; i < test ; i ++){
        int num;
        cin >> num;
        cout << p[num] << "\n";
    }

}