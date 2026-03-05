#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> st;

    while(1){
        while(!st.empty()) st.pop();
        string input;
        getline(cin,input);
        if(input == ".") break;

        for(int i = 0 ; i < input.size(); i++){
            if(input[i]=='('){
                st.push(0);
            }
            else if(input[i]==')'){
                if(st.empty()==1) {
                    st.push(0);
                    break;
                }
                else if(st.top()==1){
                    break;
                }
                st.pop();
            }
            else if(input[i]=='['){
                st.push(1);
            }
            else if(input[i]==']'){
                if(st.empty()==1) {
                    st.push(1);
                    break;
                }
                else if(st.top()==0){
                    break;
                }
                st.pop();
            }
        }
        if(st.empty()) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}