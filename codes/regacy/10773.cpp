#include <iostream>
#include <stack>

using namespace std;

stack<int> money;
int main(){
    int num_of_order;
    cin >>num_of_order;
    for(int i=0; i<num_of_order; i++){
        int x;
        cin >> x;
        if(x==0){
            money.pop();
            continue;
        }
        money.push(x);
    }
    int sum=0;
    while(1){
        if(money.empty()==1) break;
        sum+=money.top();
        money.pop();
    }
    
    cout <<sum;
}