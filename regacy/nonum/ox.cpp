#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(){
    int num;
    cin >> num;

    string* buffer = new string [num];

    int score = 0;

    for(int i=0 ; i< num; i++){
        cin >> buffer[i];
    }
    for(int i=0 ; i< num; i++){
        int _score = 0;
        int score = 0;
        for(int j = 0; j< buffer[i].length(); j++){
            if(buffer[i][j]=='O'){
                _score++;
            }
            else{
                _score = 0;
            }
            score+= _score;
        }
        cout << score <<endl;
    }

    
}