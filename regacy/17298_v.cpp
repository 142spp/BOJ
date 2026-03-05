#include <bits/stdc++.h>

using namespace std;

vector<int> nge;

class vc{
    vc(){
        int 
    }
}

void NGE(int index){
    int i=index+1;
    for(; i<nge.size(); i++){
        if(nge[index]<nge[i]) {
            printf("%d ",nge[i]);
            return ;
        }
    }
    if(i==nge.size()) cout << -1 <<" ";

}

int main(){
    int num;
    cin >> num;
    for(int i=0; i < num; i++){
        int input;
        cin >> input;
        nge.push_back(input);
    }

    for(int index = 0; index < nge.size(); index++){
        NGE(index);
    } 

    
}