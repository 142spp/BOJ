#include <iostream>

using namespace std;

int main(){
    int numlist[3] ;
    for(int i=0; i<3; i++) cin >> numlist[i];

    int legend = numlist[0]*numlist[1]*numlist[2];

    int list[10]={0,};
    int pp;
    while(legend!=0){
        pp = legend%10;
        legend /= 10;
        list[pp]++;
    }

    for(int i=0; i<10; i++){
        cout << list[i] <<endl;
    }
}