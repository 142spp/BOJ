#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;
    cin >> num;

    for(int i = 0; i<num; i++){
        int repeat;
        cin >> repeat;

        string buffer;
        cin >> buffer;

        for(int j=0; j<buffer.length(); j++){
            for(int k=0; k<repeat; k++){
                cout << buffer[j] ;
            }
        }
        cout << "\n";

    }
    return 0;
}