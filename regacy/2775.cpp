#include <iostream>

using namespace std;

int floor(int k, int n){
    if(k==0){
        return n;
    }
    else{
        int sum=0;
        for(int i=0; i<=n; i++){
            sum += floor(k-1,i);
        }
        return sum;
    }
}

int main(){
    int test;
    cin >> test;

    for(int i=0; i<test; i++){
        int k,n;
        cin >> k >> n;
        cout << floor(k,n) << "\n";
    }
    return 0;
}