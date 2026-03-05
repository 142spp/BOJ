#include <iostream>

using namespace std;

int main(){
    int numlist[10] ;
    for(int i=0; i<10; i++) cin >> numlist[i];

    int list[42]={0,};
    int pp;
    for(int i=0; i<10; i++){
        pp = numlist[i]%42;
        list[pp]++;
    }
    int index=0;
    for(int i=0; i<42; i++){
        if(list[i]!=0) index ++;
    }

    cout << index <<endl;
}