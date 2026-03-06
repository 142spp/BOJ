#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int num;
    cin >> num;
    int* list = new int[num];
    
    for(int i=0; i<num ; i++){
        cin >> list[i];
    }
       
    int max=0, min=100000000;
    for(int i=0; i<num ; i++){
        if(list[i]>max) max = list[i];
        if(list[i]<min) min = list[i];
    }
    cout << min << " " << max << endl;

    delete list;
}
