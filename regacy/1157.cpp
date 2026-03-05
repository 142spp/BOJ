#include <iostream>
#include <string>

using namespace std;

int main(){
    string buffer;
    cin >> buffer;

    int alpha [26] = {0,};

    for(int i =0; i<buffer.length(); i++){
    
        if((buffer[i]>'A'-1)&&(buffer[i]<'Z'+1)){
            alpha[buffer[i]-'A'] +=1;
        }
        else if((buffer[i]>'a'-1)&&(buffer[i]<'z'+1)){
            alpha[buffer[i]-'a'] +=1;
        }
        else{            
        }
    }
    /*
    for(int k=0; k<26; k++){
        cout << alpha[k] <<" ";
    }
    */
    int max=0;
    int max_val = 0;
    bool pre_max = 0;
    int j;
    for(j=0; j<26; j++){
        if(max_val<alpha[j]) {
            max = j;
            max_val = alpha[j];
            pre_max = false;
        }
        else if(max_val == alpha[j]) pre_max = true;
    }

    if(pre_max) cout << "?";
    else{
        printf("%c",max+'A');
    }
}