#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main(){
    int n,m; cin >> n>>m;
    for(int i=1; i<=n; i++){q.push(i);}
    int k = m;
    cout << "<";
    while(!q.empty()){
        if(q.size()==1){
            cout << q.front() << ">";
            q.pop();
        }
        else if(k <= 1) {
            cout << q.front() << ", ";
            q.pop();
            k=m;
        }else{
            q.push(q.front());
            q.pop();
            k--;
        }
    }
    return 0;
}