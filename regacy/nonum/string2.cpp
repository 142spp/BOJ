#include <iostream>
#include <string>


using namespace std;

int main(){
    string buffer;
    cin >> buffer;

    int alpha [26] ;

    for(int i = 0; i< 26; i++){
        alpha[i] = -1;
    }

    for(int i =0; i< buffer.length(); i++){
        if(alpha[buffer[i]-'a']<0){
            alpha[buffer[i]-'a'] = i;
        }
    }

    for(int i = 0 ; i < 26; i++){
        cout << alpha[i] << " " ;
    }
}