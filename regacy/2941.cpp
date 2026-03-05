#include <iostream>
#include <string>

using namespace std;

int main(){
    string buffer;
    cin >> buffer;
    int word = 0;
    for(auto i= 0; i<buffer.length(); i++){
        if(i==buffer.length()-1) word++;
        else if(buffer[i]=='c'){
            if(buffer[i+1]=='='){
                word ++;
                i++;
            }
            else if(buffer[i+1]=='-'){
                word ++;
                i++;
            }
            else word++;
        }
        else if(buffer[i]=='d'){
            if(buffer[i+1]=='z'){
                if(buffer[i+2]=='='&&i!=buffer.length()-2){
                    word ++;
                    i+=2;
                }
                else{
                    word ++;
                }
            }
            else if(buffer[i+1]=='-'){
                word ++;
                i++;
            }
            else word++;
   
        }
        else if(buffer[i]=='l'){
            if(buffer[i+1]=='j'){
                word ++;
                i++;
            }
            else word++;

        }
        else if(buffer[i]=='n'){
            if(buffer[i+1]=='j'){
                word ++;
                i++;
            }
            else word++;

        }
        else if(buffer[i]=='s'){
            if(buffer[i+1]=='='){
                word ++;
                i++;
            }
            else word++;

        }
        else if(buffer[i]=='z'){
            if(buffer[i+1]=='='){
                word ++;
                i++;
            }
            else word++;

        }
        else{
            word ++;
        }
    }

    cout << word;
}