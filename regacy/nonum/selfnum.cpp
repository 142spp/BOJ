#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int next(int n){
    int sum=0;
    int pre=n;
    while(n!=0){
        sum+=n%10;
        n/=10;
    }
    return sum+pre;
}

int main(){
    vector<int> list={0};
    for(int i=0; i<10000; i++){
        list.push_back(i+1);
    }
    for(int i=0; i<10000; i++){
        if(find(list.begin(),list.end(),next(i))!=list.end()){
            list.erase(find(list.begin(),list.end(),next(i)));
        }
    }

    for(auto iter = list.begin(); iter!=list.end(); iter++){
        cout << *iter << endl;
    }
    return 0;
}