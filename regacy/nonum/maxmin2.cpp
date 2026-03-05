#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
    int num;
    num = 9;
    int* list = new int[num];
    
    for(int i=0; i<num ; i++){
        cin >> list[i];
    }
    
    int index;
    int max=0;
    for(int i=0; i<num ; i++){
        if(list[i]>max){
            max = list[i];
            index = i;
        } 
    }
    cout   << max << "\n" <<  index+1 <<  endl;

    delete list;
}
