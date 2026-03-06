#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(null);

    stack<int> st;
    int num_of_order;
    cin >> num_of_order;
    for(int i =0 ; i< num_of_order ; i++){
        string input;
        cin >> input;
        
        if(input == "push"){
            int target;
            cin >> target;
            st.push(target);
        }
        else if(input == "pop"){
            if(st.empty()==1){
                cout << -1 <<"\n";
                continue;
            }
            cout << st.top() <<"\n";
            st.pop();
        }
        else if(input == "size"){
            cout << st.size() <<"\n";
        }
        else if(input == "empty"){
            cout << (int)st.empty()<<"\n";
        }
        else if(input == "top"){
            if(st.empty()==1){
                cout <<-1 <<"\n";
                continue;
            }
            cout << st.top()<<"\n";
        }

    }
}
