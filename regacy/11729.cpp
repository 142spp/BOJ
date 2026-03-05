#include <iostream>

using namespace std;

int hanoi_print(int depart, int dest, int k , int n){
    if(n==1) {
        cout << depart << " " << dest <<"\n";
        return 1;
    }
    return  hanoi_print(depart,k,dest,n-1) + hanoi_print(depart,dest,k,1) + hanoi_print(k,dest,depart,n-1);
}


int hanoi(int depart, int dest, int k , int n){
    if(n==1) {
        return 1;
    }
    return  hanoi(depart,k,dest,n-1) + hanoi(depart,dest,k,1) + hanoi(k,dest,depart,n-1);
}

int main(){
    int num;
    cin >> num;
    cout << hanoi(1,3,2,num) << endl;
    hanoi_print(1,3,2,num);
}