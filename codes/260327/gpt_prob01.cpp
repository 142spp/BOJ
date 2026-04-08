#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n; cin >> n;
    vector<string> files(n);
    for(int i=0; i<n; i++){
        cin >> files[i];
    }
    sort(files.begin(),files.end(), [](string a, string b){
        string a_head,b_head, a_num,b_num;
        int i = 0;
        while(i<(int)a.size()&& !isdigit(a[i])) i++;
        int j = i;
        while(j<(int)a.size()&& isdigit(a[i])) j++;
        a_head = a.substr(0,i);
        a_num = a.substr(i,j-i);

        i = 0; 
        while(i<(int)b.size()&& !isdigit(b[i])) i++;
        j = i;
        while(j<(int)b.size()&& isdigit(b[i])) j++;
        b_head = b.substr(0,i);
        b_num = b.substr(i,j-i);
        
        for(auto& c : a_head) c = tolower(c);
        for(auto& c : b_head) c = tolower(c);
        
        if(a_head != b_head) return a_head > b_head;
        return stoi(a_num) < stoi(b_num);
            
    });
    for(auto f : files){
        cout << f << " ";
    }
}