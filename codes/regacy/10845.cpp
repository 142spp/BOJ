#include <bits/stdc++.h>

using namespace std;

class dq{
private: 
    vector<int> vc;
public:
    void push_back(int i){
        vc.push_back(i);
    }
    void pop_front(){
        if(vc.size()==0){ cout << -1; return;}
        cout << vc.front();
        vector<int> tmp(vc.size()-1);
        copy(vc.begin()+1,vc.end(),tmp.begin());
        vc = tmp;
    }
    void size(){
        cout << vc.size();
    }
    void empty(){
        cout << vc.empty();
    }
    void front(){
        if(vc.size()==0) cout << -1;
        else cout << vc.front();
    }
    void back(){
        if(vc.size()==0) cout << -1;
        else cout << vc.back();
    }
};

vector<string> strs = {"push","pop","size","empty","front","back"};
int choosing(string command){
    for(int i = 0 ; i<strs.size(); i++){
        if(command.compare(strs[i])==0) return i;
    }
    return -1;
}

int main(){
    dq deck;
    int n; cin >> n;
    while(n--){
        string command;
        cin >> command;
        int i;
        switch (choosing(command))
        {
        case 0:
            cin >> i;
            deck.push_back(i);
            break;
        case 1:
            deck.pop_front();cout << "\n";
            break;
        case 2:
            deck.size();cout << "\n";
            break;
        case 3:
            deck.empty();cout << "\n";
            break;
        case 4:
            deck.front();cout << "\n";
            break;
        case 5:
            deck.back();cout << "\n";
            break;
        case -1:
            cout << "error" << "\n";
        }
        
    }
    return 0;
}