#include <iostream>
#include <math.h>

using namespace std;

int main(){
    

    bool is_nprime [10001];
    for(int i=3; i<=sqrt(10000); i+=2){
        for(int j=3; j<=10000/i; j+=2){
            is_nprime[i*j]=1;
        }
    }

    for(int k=4; k<=10000; k+=2){
        is_nprime[k]=1;
    }

    int test;
    cin >> test;

    for(int i=0; i<test; i++){

        int num;
        cin >> num;

        int p1=num/2, p2=num/2;
        
        while(1){

            if(!is_nprime[p1]&&!is_nprime[p2]){
                cout << p1 <<" " <<p2 <<"\n";
                break;
            }
            
            else{
                p1 --;
                p2 ++;
            }
        }
    }
}