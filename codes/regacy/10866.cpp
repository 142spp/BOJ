#include <bits/stdc++.h>

using namespace std;

class dq{
private: 
    vector<int> vc;
public:
    void push_front(int i){
        vector<int> tmp;
        tmp.push_back(i);
        tmp.resize(vc.size()+1);
        copy(vc.begin(),vc.end(),tmp.begin()+1);
        vc = tmp;
    }
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
    void pop_back(){
        if(vc.size()==0){ cout << -1; return;}
        cout<< vc.back();
        vc.pop_back();
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

vector<string> strs = {"push_front","push_back","pop_front","pop_back","size","empty","front","back"};
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
            deck.push_front(i);
            break;
        case 1:
            cin >> i;
            deck.push_back(i);
            break;
        case 2:
            deck.pop_front();cout << "\n";
            break;
        case 3:
            deck.pop_back();cout << "\n";
            break;
        case 4:
            deck.size();cout << "\n";
            break;
        case 5:
            deck.empty();cout << "\n";
            break;
        case 6:
            deck.front();cout << "\n";
            break;
        case 7:
            deck.back();cout << "\n";
            break;
        case -1:
            cout << "error" << "\n";
        }
        
    }
    return 0;
}