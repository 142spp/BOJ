#include <bits/stdc++.h>
using namespace std;

int main(void){
    string text = "HelloWorld!";
    string target = "loo";
    int d = 2;

    int dp[3001] ={};
    if(target[0] == text[0]) dp[0] = 1;
    for(int i=1; i<text.size(); i++){
        for(int j=i-1; j>=i-d&&j>=0; j--){
            if(target[dp[j]] == text[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    for(int i=0; i<text.size(); i++){
        cout << dp[i] << " ";
    }
    if(*max_element(dp, dp+text.size()) == target.size()) cout << "YES";
    else cout << "NO";

    return 0;
}