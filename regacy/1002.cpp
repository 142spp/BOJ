#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

class xy{
public:
    double x;
    double y;
    double r;
};

int main(){
    int num;
    cin >> num;

    for(int i = 0 ; i <num; i++){
        xy a;
        xy b;
        scanf("%lf %lf %lf %lf %lf %lf" ,&a.x,&a.y,&a.r,&b.x,&b.y,&b.r );
        double distance = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
        if(a.x==b.x&&a.y==b.y&&a.r==b.r){
            cout << -1 << endl;
        }
        else if(distance>(a.r+b.r) || distance < abs(a.r - b.r)){
            cout << 0 <<endl;
        }
        else if(distance==(a.r+b.r)|| distance == abs(a.r - b.r)){
            cout << 1 <<endl;
        }
        else {
            cout << 2 <<endl;
        }
    }
    
}