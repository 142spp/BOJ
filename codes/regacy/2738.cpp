#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int>> mat_A(n,vector<int>(m));
    vector<vector<int>> mat_B(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat_A[i][j];       
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> mat_B[i][j];       
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << mat_A[i][j] + mat_B[i][j] << " ";
        }
        cout << "\n";
    }
    
}