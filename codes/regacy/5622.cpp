#include <iostream>
#include <string>
#include <vector>

using namespace std;

int list [26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

int main(){
    string word;
    cin >> word;

    int sum = 0;
    for(int i = 0; i < word.length(); i++){
        sum += list[word[i]-'A']+1;
    }

    cout <<sum;
}