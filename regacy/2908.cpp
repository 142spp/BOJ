#include <iostream>
#include <string>

using namespace std;

string reversebuffer(string buffer){
    string newbuf;
    for(auto i = buffer.length()-1; i>0; i--){
        newbuf.push_back(buffer[i]);
    }
    newbuf.push_back(buffer[0]);
    return newbuf;
}

int main(){
    string buffer1;
    string buffer2;

    cin >> buffer1;
    cin >> buffer2;
    if(reversebuffer(buffer1).compare(reversebuffer(buffer2))>0){
        cout << reversebuffer(buffer1);
    }
    else{
        cout << reversebuffer(buffer2);
    }
}