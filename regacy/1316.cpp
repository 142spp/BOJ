#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;
    cin >> num;

    int sum = 0;
    for(int i = 0 ; i < num ; i ++){
        bool alpha [26] = {false,};

        string buffer;
        cin >> buffer;
        char previous = ' ';
        for( int j = 0 ; j < buffer.length(); j++){
            if(previous == buffer[j]) continue;
            else{
                previous=buffer[j];
                if(alpha[buffer[j]-'a']){
                    sum--;
                    break;
                }
                else{
                    alpha[buffer[j]-'a'] = true;
                }
            }

        }
        sum ++;
    }
    cout << sum;
}