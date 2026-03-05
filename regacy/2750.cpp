#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num;
    cin >> num;

    vector<int> numvector ;

    for(int i=0; i<num; i++){
        int input;
        cin >> input;

        numvector.push_back(input);
    }

    sort(numvector.begin(),numvector.end());
    for(int i=0; i<num; i++){
        cout << numvector[i] <<"\n";
    }

}