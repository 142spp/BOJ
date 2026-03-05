#include <iostream>
#include <math.h>
using namespace std;

int teleport(long int distance){
    int index=0;
    long int sum_of_k=0;
    int k;
    for( k=1; sum_of_k<(float)distance/2; k++){
        index++;
        sum_of_k+=k;
        //cout << "\n" << index ;
    }
    if(sqrt(distance) <= index)
        return (index*2) -1;
    else{
        return index*2;
    }
}


int main(){
    int num;
    cin >> num;
    long int x=0,y=1 ;
    
    for(int i=0 ; i<num; i++){
        cin >> x >> y;

        long int dis = y-x;
        //cout << dis <<" : ";
        
        //cout << teleport2(dis) << "   ";
        cout << teleport(dis) <<endl;
        //y++;
    }
    
}