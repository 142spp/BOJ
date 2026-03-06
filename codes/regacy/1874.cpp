#include <bits/stdc++.h>

using namespace std;

int main() {
    int index;
    cin >> index;
    vector<int> input_array;
    vector<int> output_array;
    vector<char> output;

    for (int i = 0; i < index; i++) {
        int input;
        cin >> input;
        input_array.push_back(input);
    }
    stack<int> st;
    st.push(0);
    int pre = 1;

    while (input_array.size() != 0) {
        if (st.top() == input_array.front()) {
            output_array.push_back(input_array.front());
            st.pop();
            output.push_back('-');
            input_array.erase(input_array.begin());
        } else {
            st.push(pre);
            output.push_back('+');
            pre++;
            if (st.size() > index + 1) {
                printf("NO");
                return 0;
            }
        }
    }

    for (auto iter = output.begin(); iter != output.end(); iter++) {
        printf("%c\n", *iter);
    }
}