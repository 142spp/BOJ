#include <iostream>
#include <vector>

using namespace std;

long long sum(vector<int> &a){
    int sum=0;
    for(int i=0; i<a.size(); i++){
        sum += a[i];
    }
    return sum;
}

int main(){
    vector<int> a = {1,3,4};
    cout << sum(a) <<endl;
}