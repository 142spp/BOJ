#include <iostream>
#include <string>

using namespace std;

int main(){
    string buffer;
    getline(cin,buffer);
    int word=0;


    for(int i=0; i<buffer.length(); i++){ 
        if(buffer[i]==' ') word ++;
    }
    if((buffer[0]==' ')) word--;
    if(buffer[buffer.length()-1]==' ') word--;

    cout << word+1;
}