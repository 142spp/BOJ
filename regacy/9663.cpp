#include <iostream>
#include <vector>

using namespace std;

int n,count;
vector<int> queen;

void dfs( int index){
    if(index == 0 ){
        for(int i=0; i<n; i++){
            queen[index] = i;
            dfs( index+1);
        }
    }
    else if(index == n){
        count ++;
    }
    else{
        int* unable = new int[n];

        for(int i=0; i<n; i++) unable[i]=0;

        for(int i=0; i<index; i++){
            
            unable[queen[i]] = 1;

            if(queen[i]+(index-i) <= n-1)
                unable[queen[i]+(index-i)]= 1;
            if(queen[i]-(index-i) >= 0)
                unable[queen[i]-(index-i)]= 1;
        }

        for(int i=0; i < n; i++){
            if(unable[i]==0){
                queen[index] = i;
                dfs(index+1);
            }
        }
        delete[] unable;
    }

}

int main(){
    count =0;

    cin >> n;

    for(int i=0; i<n; i++){
        queen.push_back(0);
    }

    dfs(0);

    printf("%d", count);
    return 0;
}