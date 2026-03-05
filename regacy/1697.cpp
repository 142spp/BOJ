#include <bits/stdc++.h>

#define MAX 100001
#define INF 100002

using namespace std;

int memory[MAX]={};
int target;

/*  3 29
    3 -> 6 -> 12 -> 24 -> 25 -> 26 -> 27 -> 28 -> 29
    3 -> 6 -> 12 -> 13 -> 26 -> 27 -> 28 -> 29
    3 -> 6 -> 12 -> 13 -> 14 -> 28 -> 29
    3 -> 6 -> 7 -> 14 -> 28 -> 29
*/

/*  2 17
    2   4   8   16  15
                    17
                9   18
                    10
            5   10  
                6
        3   6   12
                7
            4   8
                5
*/

/*  2 9
    2   4   8   9   correct answer
            5   10  9
                6   12 11 10 9
        3   6   12  11 10 9
                7   14 13 12 11 10 9
            4   8   16
                5   


*/

// 3 10 // 3 6 12 11 10 // 3 6 5 10 // 3 4 5 10

/*  2 14
    2   4   8   16  15  14
                9   10
                    8   ...
                7   14
*/

/*  3 15
    3 6 12 13 14 15
    3 6 7 14 15
    3 4 8 16 15
*/

/*  2 18
    2 4 8 16 17 18
    2 4 8 9 18
    2 4 5 10 20 
*/

/*  5 18
    5 10 9 18
    5 10 20 19 18
    5 6 12 ...
    5 6 7 ...
    5 6 7 8 ...
    5 6 7 8 9 18
*/

/*  3 7
    3   6   12  11 10 9 8 7
            7
            5
        4   
*/

int dp(int n){
    cout << n << " ";
    if(memory[n]>0) return memory[n];

    if()
    if(n==target) memory[n] = 0;
    else if(n > target) memory[n] = dp(n-1) + 1;
    else if(n*2 > target) memory[n] = min(dp(n-1),dp(n*2))+1;
    else memory[n] = min(dp(n+1),dp(n*2)) + 1;

    return memory[n];
}


int main(){
    int n; cin >> n >> target;
    cout << dp(n);
}