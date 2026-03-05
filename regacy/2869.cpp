#include <iostream>

using namespace std;



int main(){

    int A,B,V;
    cin >> A >> B >> V;

    double day = (double) (V-A)/(A-B);
    int days = day;
    if(days < day) days ++;
    cout << days+1;

}