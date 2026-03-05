#include <bits/stdc++.h>

using namespace std;

int triangle[500][500];
int max_table[500][500] = {0,};

int max_val = 0;

int max_tri(int i, int j){
    if(max_table[i][j]!=0) return max_table[i][j];
    int val = triangle[i][j];

    if (i==0) { 
        max_table[i][j] = val;
    }
    else if(j==0){
        max_table[i][j] = max_tri(i-1,j) + val;
    }
    else if(j==i){
        max_table[i][j] = max_tri(i-1,j-1) + val;
    }
    else{
        max_table[i][j] = (max_tri(i-1,j-1) > max_tri(i-1,j)) 
        ? max_tri(i-1,j-1) + val : max_tri(i-1,j) + val;
    }
    if(max_val < max_table[i][j]) max_val = max_table[i][j];
    return max_table[i][j];
}

int main(){
    int n; cin >> n;
    for(int i =0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> triangle[i][j];
            max_tri(i,j);
        }
    }
    cout << max_val;
}