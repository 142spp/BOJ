#include <iostream>

using namespace std;

int main(){
    int len;
    cin >> len;
    string buffer;
    cin >> buffer;

    string buffer2(buffer,len-5);
    cout << buffer2 <<endl;
}