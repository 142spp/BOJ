#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;

    int* list = new int [num];
    
    for(int i=0; i<num; i++){
        cin >> list[i];
    }
    
    int max;
    for(int i=0; i<num-1; i++){
        if(list[i]==list[i+1]){
            cout << "NO" << endl;
            return 0;
        }
        else if(list[i]>list[i+1]){
            max= i;
            break;
        }
    }

    for(int j=max+1; j<num-1; j++){
        if(list[j]<list[j+1]||list[j]==list[j+1]){
            cout << "NO" <<endl;
            return 0;
        }
    }

    cout << "YES" <<endl;
}