#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;

    int* list = new int [num];

    for(int i=0; i< num; i++){
        cin >> list[i];
    }
    int i_index;
    int j_index;
    int max = 0;
    for(int i=0; i<num; i++){
        for(int j=i+1; j<num; j++){
            if(list[i]-list[j]>2||list[i]-list[j]<-2||j==num-1){
                
                int len = j - i;
                if(j==num-1&&!(list[i]-list[j]>2)&&!(list[i]-list[j]<-2)) len++;
                cout << i <<" " << j << " " << len << endl;
                if(len > max || (i_index<i && j_index >j) ) {
                    
                    max = len;
                    i_index = i;
                    j_index = j;
                }

                break;
            }
        }
    }
    if(max == 0) max = num;

    cout << max << endl;
}