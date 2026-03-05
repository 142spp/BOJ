#include <iostream>
#include <vector>

using namespace std;



int main(){

    int coin_num;
    int target_money;
    int counts = 0;

    cin >> coin_num >> target_money;

    int* coins = new int[coin_num];

    for(int i=0; i<coin_num; i++){
        cin >> coins[i] ;
    }

    int i=0;

    for(; i< coin_num; i++){
        if(coins[i]>target_money) break;
    }

    if(i==coin_num){
        counts += (target_money / coins[coin_num-1]);
        target_money %= coins[coin_num-1];

        i=0;

        for(; i< coin_num; i++){
            if(coins[i]>target_money) break;
        }
    }

    for(int j=i; j>=0; j--){
        if(coins[j]>target_money) continue;
        
        counts += (target_money / coins[j]);
        target_money %= coins[j];
    }
    printf("%d",counts);

}