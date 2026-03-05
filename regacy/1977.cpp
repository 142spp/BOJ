#include <iostream>
#include <math.h>


using namespace std;

int main(){
    int n1;
    int n2;
    cin >> n1;
    cin >> n2;
    int min=n2+1;
    int sum = 0;
    for(int i=n1; i<n2+1; i++){
        for(int j=0; j<i+1; j++){
            if(j*j == i){
                sum += i;
                if(i < min) min = i;
                break;
            }
            else continue;
        }
    }

    if(sum == 0 && (n1!=0) && n2!=0) {
        sum = -1;
        cout << sum ;
    }
    else    
        cout << sum << "\n" << min ;
}