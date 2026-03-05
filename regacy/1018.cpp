#include <bits/stdc++.h>

using namespace std;

vector<string> chess;
vector<vector<char>> wb;
vector<vector<char>> bw;

void make_chess(int n, int m){
    for(int i=0; i<n; i++){
        vector<char> temp_a;
        vector<char> temp_b;
        for(int j=0; j<m; j++){
            if( (i+j) % 2 == 0 ) { 
                temp_a.push_back('W');
                temp_b.push_back('B');
            }
            else{
                temp_a.push_back('B');
                temp_b.push_back('W');    
            } 
        }
        wb.push_back(temp_a);
        bw.push_back(temp_b);
    }
}

int true_comp(int n, int m){
    int wb_ = 0 , bw_ = 0;
    for(int i= n; i< n+8; i++ ){
        for(int j=m; j< m+8; j++){
            if(chess[i][j] != wb[i][j]) wb_++;
            else if(chess[i][j] != bw[i][j]) bw_++;
        }
    }
    if(wb_ < bw_) return wb_;
    else return bw_;
}

int comp(int n, int m){
    int min = n*m+1;
    for(int i=0; i<n-7; i++){
        for(int j=0; j<m-7; j++){
            int comp_val = true_comp(i,j);
            if(min > comp_val) min = comp_val;
        }
    }
    return min;
}

int main(){
    int n, m;
    cin >> n >> m;
    make_chess(n,m);

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        chess.push_back(str);
    }
    cout << comp(n,m) << "\n";
}