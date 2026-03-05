#include <iostream>

using namespace std;

// int fibonaci(int n){
//     if(n==0) return 0;
//     if(n==1) return 1;
//     else return fibonaci(n-1) + fibonaci(n-2);
// }

int main(){
    // for(int i = 2;  i < 1000000; i++){
    //     printf("%d\n",fibonaci(i));
    // }
    //printf("%d", fibonaci(num+1)%15746);
    int* pibo = new int[1000002];
    pibo[0]=0;
    pibo[1]=1;
    pibo[2]=1;
    for(int i=3; i<=1000001; i++){
        pibo[i]=(pibo[i-1]+pibo[i-2])%15746;
    }

    int num;
    cin >> num;

    printf("%d",pibo[num+1]);


}