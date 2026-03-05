#include <iostream>

using namespace std;

bool is_hansu(int num){
    int d = (num/10)%10 - num%10;
    if(num==100) return 0;
    while(num/10!=0){
        if(((num/10)%10 - num%10)==d){
            
            num/=10;
            continue;
        } 
        else{
            return 0;
        }
    }
    return 1;
}

int main(){
    int num;
    cin >> num;
    int sum=0;
    for(int i=1; i<num+1; i++){
        if(is_hansu(i)) sum++;
    }
    cout << sum <<endl;
}