#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> arr;
    for(int i =0; i<n;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int max = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k] > m) continue;
                else if(arr[i]+arr[j]+arr[k] > max) max = arr[i]+arr[j]+arr[k];
            }        
        }
    }
    cout << max;
    
}