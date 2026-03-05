#include <bits/stdc++.h>

using namespace std;

int ct =0,r,c;
long long quad(int i, int j, int len){
    if(len==1) return 1;
    len/=2;
    long long val = pow(len,2);
    if(i<=r && r<i+len){
        if(j<=c && c<j+len){
            return quad(i,j,len);
        }else{
            return val + quad(i,j+len,len);
        }
    }else{
        if(j<=c && c<j+len){
            return 2*val + quad(i+len,j,len);
        }else{
            return 3*val + quad(i+len,j+len,len);
        }
    }
}

void passing (int i, int j, int len){
	if(len == 1) {ct ++; cout << i << " " << j << "\n";}
    else{
        len/=2;
        passing(i,j,len);
        passing(i,j+len,len);
        passing(i+len,j,len);
        passing(i+len,j+len,len);
    }
    if(i==r && j==c) {cout << ct - 1  ; exit(0);} 
}

int main(){
    int n; cin >> n >> r >> c;
    passing(0,0,pow(2,n));
//    cout << quad(0,0,pow(2,n))-1;
}
