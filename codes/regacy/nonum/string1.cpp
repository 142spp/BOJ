#include <iostream>
#include <string>

using namespace std;

int main(){
    int num;
    cin >> num;

    string buffer;
    cin >> buffer;

    int sum=0;
    for(int i=0; i<buffer.length(); i++){
        sum += buffer[i]-'0';
    }
    cout << sum << endl;
}