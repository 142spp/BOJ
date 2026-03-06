#include <bits/stdc++.h>

using namespace std;

bool is_equal(int* arr1, int* arr2){
    for(int i=0; i<8; i++){
        if(arr1[i]!=arr2[i]) return 0;
    }
    return 1;
}

int main(){
    int ascending[8]={1,2,3,4,5,6,7,8};
    int descending[8]={8,7,6,5,4,3,2,1};
    int* input_arr = new int[8];
    for(int i=0; i<8; i++){
        cin >> input_arr[i];
    }
    if(is_equal(ascending,input_arr)) cout << "ascending";
    else if(is_equal(descending,input_arr)) cout << "descending";
    else cout << "mixed";
}