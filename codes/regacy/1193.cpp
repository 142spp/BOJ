#include <iostream>

using namespace std;

int main(){
    int num;
    cin>> num;
    int i , j,even=1;
    for( i =1 ; ; i++,even++){
        int k=1;
        for(j=i; j>0; j--, k++){
            if(num==1) {
                if(even%2==0)cout << k << "/" <<j;
                else cout << j << "/" <<k;
                return 0;
            }
            num--;
        }
    }
}