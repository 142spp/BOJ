/*
문제
최근 들어 개인정보 유출에 대한 뉴스를 많이 본 수형이는 한 사이트의 비밀번호가
유출 되더라도 다른 사이트에서 똑같은 비밀번호로 접속할 수 없도록 사이트마다
비밀번호를 다르게 설정하기로 다짐했다. 많이 고민한 결과 수형이는 눈을 감고
키보드를 막 쳐서 나온 두 문자열에서 공통으로 존재하는 가장 긴 부분 문자열을
비밀번호로 하기로 하였다. 수형이가 눈을 감고 만든 두 문자열이 주어졌을 때
비밀번호를 만드는 프로그램을 만들어보자.

입력
첫째 줄과 둘째 줄에 수형이가 눈을 감고 만든 두 문자열이 주어진다. 문자열은
알파벳 대문자로만 이루어져 있으며, 길이는 최대 40자이다. 빈 문자열은 주어지지
않는다. 가장 긴 부분 문자열은 반드시 하나만 존재한다.

출력
첫 번째 줄에 입력으로 주어진 두 문자열로 만든 비밀번호를 출력한다.
*/

#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string A, B;
    cin >> A >> B;

    const int n = static_cast<int> (A.size());
    const int m = static_cast<int> (B.size());

    vector<vector<int>> dp(n+1,vector<int> (m+1,0));

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1] +1;
            } else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    //back_tracking
    int i = n;
    int j = m;
    string ans;
    while(i > 0 && j >0){
        if(A[i-1] == B[j-1]){
            ans.push_back(A[i-1]);
            i--; j--;
        }
        else if (dp[i-1][j] >= dp[i][j-1]){
            i--;
        } else{
            j--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<< ans << endl;

    return 1;
}