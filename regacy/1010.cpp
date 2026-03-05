#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;
    for(int i =0; i<num; i++){
        int a,b;
        cin >> b >> a;


        unsigned long long int comb=1;
        int k=1;
        for(int j=a; j>a-b; j--){
            
            comb *= j;
            comb /= k++;
        }

        cout << comb << "\n";
    }
}