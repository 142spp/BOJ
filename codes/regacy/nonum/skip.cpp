#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(){
    int num;
    cin >> num;

    string buffer;
    cin >> buffer;

    bool is_token=0;

    if(buffer.length()<26) cout << buffer;
    else{
        for(int i=11; i<buffer.length()-12; i++){
            cout << buffer[i];
            if(buffer[i]=='.') is_token=1;
        }
        cout << "\n";

        if(!is_token){
            cout << buffer.substr(0,11);
            cout << "...";
            cout << buffer.substr(buffer.length()-11,buffer.length());
        }
        else{
            cout << buffer.substr(0,9);
            cout << "......";
            cout << buffer.substr(buffer.length()-10,buffer.length());
        }
    }
    return 0;
}