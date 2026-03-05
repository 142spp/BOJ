#include <bits/stdc++.h>

using namespace std;

int main(){
    int num_of_num;
    cin >> num_of_num;
    stack<pair<int,int>> st;
    vector<int> answer(num_of_num,-1);
    for(int i=0; i<num_of_num; i++){
        int input;
        cin >> input;

        while(!st.empty()){
            if(st.top().second<input) {
                answer[st.top().first] = input;
                st.pop();
            }
            else{
                break;
            }
        }
        st.push(pair<int,int> (i,input));
    }

    for(auto iter = answer.begin(); iter!=answer.end(); iter++){
        cout << *iter << " " ;
    }
    return 0;
    
}