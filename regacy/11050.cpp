#include <bits/stdc++.h>

using namespace std;

vector<int*> pascal;

int main(){
    int n,k;
    cin >> n >> k;

    for(int i=0; i<=n; i++){
        int* arr = new int [i+1] ();
        for(int j=0; j<=i; j++){
            if(j==0||j==i){
                arr[j]=1;
            }
            else{
                arr[j]=(pascal.back()[j-1]+pascal.back()[j] )%10007;
            }
        }
        pascal.push_back(arr);
    }

    cout << pascal[n][k];
}