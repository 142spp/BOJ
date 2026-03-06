#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> st;
    int num_of_order;
    cin >> num_of_order;
    for(int j = 0 ; j < num_of_order ; j++){
        while(!st.empty()) st.pop();
        string input;
        cin >> input;

        for(int i = 0 ; i < input.size(); i++){
            if(input[i]=='('){
                st.push(0);
            }
            else if(input[i]==')'){
                if(st.empty()==1) {
                    st.push(0);
                    break;
                }
                st.pop();
            }
        }
        if(st.empty()==1) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}