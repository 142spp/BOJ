#include <bits/stdc++.h>

using namespace std;

int table[101][101][101] = {-1,};

int w(int a,int b,int c){
    int t_a = a+50, t_b = b+50 , t_c = c+50;
    if(table[t_a][t_b][t_c]>0) return table[t_a][t_b][t_c];

    int answer ;

    if(a<= 0 || b<= 0 || c<= 0 )        answer = 1;
    else if(a > 20 || b>20 || c>20)     answer = w(20,20,20);
    else if(a<b && b<c)                 answer = w(a,b,c-1) + w(a,b-1,c-1) -w(a,b-1,c);
    else                                answer = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);

    table[t_a][t_b][t_c] = answer;
    return answer;
}

int main(){
    while(true){
        int x,y,z;
        cin >> x >> y >> z;
        if(x==-1&&y==-1&&z==-1) break;
        cout << "w(" << x << ", " << y << ", " << z << ") = " << w(x,y,z) << "\n";
    }
}