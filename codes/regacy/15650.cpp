#include <iostream>
#include <vector>

using namespace std;

vector<int> answer;

int m,n;

void dfs(int index){
    if(index == n){
        for(auto iter = answer.begin(); iter!= answer.end(); iter++){
            printf("%d ", *iter);
        }
        printf("\n");
    }

    else{
        for(int i=1; i<=m; i++){
            if(!index){ 
                answer[index] = i;
                dfs(index +1);
            }
            else{
                if(answer[index-1] < i){
                    answer[index] = i;
                    dfs(index +1);
                }
            }
        }
    }
}

int main(){

    cin >> m  >> n;

    for(int i=0; i<n; i++){
        answer.push_back(0);
    }

    dfs(0);

    return 0;
}