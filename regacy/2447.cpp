#include <iostream>
#include <math.h>
#include <cmath>

using namespace std;

int main(){
    int num;
    cin >> num;

    int po_num = num;
    int power;
    for(power =0 ; po_num>1 ; power++){
        po_num/=3;
    }
    // cout << power <<endl;
    bool** star =new bool* [num];
    for(int i=0; i<num; i++){
        star[i] = new bool [num];
    }

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            star[i][j] =0;
        }
    }

    for(;power>0;power--){

        int pwe=pow(3,power);

            for(int i=0; i<pwe/3; i++){
                for(int j=0; j<pwe/3; j++){
                    
                    for(int m=0; m<num/pwe; m++){
                        for(int n=0; n<num/pwe; n++){

                            star[(num/pwe*i*3)+num/pwe+m][(num/pwe*j*3)+num/pwe+n] =1;

                        }
                    }
            }
        }
    }


    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            if(!star[i][j]) cout << "*" ;
            else cout << " ";
        }
        cout <<endl;
    }


}