#include <iostream>
#include <map>

using namespace std;

int main(){

    map<int,int> m;
    int num_of_building;
    cin >> num_of_building;

    for(int i=0; i<num_of_building; i++){
        int start,height,end;
        cin >> start >> height >> end;

        for(int j=start; j<=end; j++){
            if(m[j]<height) m[j]=height;
        }
    }
    int previous=0;
    for(auto iter = m.begin(); iter!=m.end(); iter++){
        if(iter->second!=previous) {
            cout << iter->first <<" " << iter->second <<" ";
            previous = iter->second;
        }
        if((++iter)->first!=iter->first){
            cout << iter->first +1 << " " << 0 << " ";
            iter--;
        }
    }
}