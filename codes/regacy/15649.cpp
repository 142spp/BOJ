#include <iostream>
#include <vector>

using namespace std;

vector<bool> check;
vector<int> answer;

int m,n;

int dfs(int index){

    if(index == n){
        for(auto i = answer.begin(); i!=answer.end(); i++)
            printf("%d ",*i);
        printf("\n");
        return 0;
    }
    
    else {
        for(auto iter=1; iter<=m; iter ++){
            if(!check[iter]){
                answer[index] = iter;
                check[iter] = true;
                dfs(index+1);
                check[iter] = false;
            }
        }
    }
    return 0;
}

int main(){

    cin >> m  >> n;

    for(int i = 0; i < m+1; i++){
        check.push_back(false);
    }
    for(int i=0; i<n; i++){
        answer.push_back(0);
    }

    dfs(0);

    return 0;
}