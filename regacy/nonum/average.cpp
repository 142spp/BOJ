#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;
    float* list = new float [num] ;

    for(int i =0; i< num; i++)
    {
        cin >> list[i];
    }
    float max = 0;
    for(int i = 0; i< num; i++){
        if(list[i] > max) max = list[i];
    }

    float sum = 0;
    for(int i=0; i<num ; i++){
        sum += static_cast<float> (list[i]/max)*100;
    }

    cout << sum/num <<endl;
}