#include <bits/stdc++.h>

using namespace std;
vector<string> string_vec;
vector<char> Caracter; 

int l,c;
bool is_alpha(string str);
bool is_moja(string str);
void dfs(string str, int index){
    if(!is_alpha(str)) return;
    else if(index==l){
        if(is_moja(str)) string_vec.push_back(str);
    }
    else{
        for(int i=0; i<c; i++){
            if(str.find(Caracter[i])!=string::npos) continue;
            else{
                dfs(str+Caracter[i],index+1);
            }
        }
    }
}

bool is_alpha(string str){
    if(str.size()==0) return 1;
    for(int i=0; i<str.size()-1; i++){
        if(str[i]>str[i+1]) return 0;
    }
    return 1;
}

bool is_moja(string str){
    int mo=0,ja=0;
    for(int i=0; i<str.size(); i++){
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u') mo++;
        else ja++;
    }

    if(mo>=1&&ja>=2) return 1;
    else return 0;
}

int main(){
    cin >> l >> c;
    for(int i=0; i<c; i++){
        char ch;
        cin >> ch;
        Caracter.push_back(ch);
    }
    sort(Caracter.begin(),Caracter.end());
    dfs("",0);
    //sort(string_vec.begin(),string_vec.end());

    for(auto iter=string_vec.begin(); iter!=string_vec.end(); iter++){
        cout << *iter << "\n";
    }
}