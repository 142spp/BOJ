#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    priority_queue<int> pq_max;
    priority_queue<int,vector<int>,greater<int>> pq_min;
    multiset<int> s;

    while(n--){
        int m; cin >> m;
        s.clear();
        while(!pq_max.empty()) pq_max.pop();
        while(!pq_min.empty()) pq_min.pop();

        while(m--){
            char c; int i; cin >> c >> i;
            switch(c){
                case 'I':
                    pq_max.push(i);
                    pq_min.push(i);
                    s.insert(i);
                    break;
                case 'D':
                    if(s.size()==0) continue;
                    if(i==1){
                        s.erase(s.find(pq_max.top())); pq_max.pop();
                    }
                    else if(i==-1){
                        s.erase(s.find(pq_min.top())); pq_min.pop();
                    }
                    while(s.find(pq_max.top())==s.end() && !pq_max.empty()){
                        pq_max.pop(); }
                    while(s.find(pq_min.top())==s.end() && !pq_min.empty()){
                        pq_min.pop(); }
                    break;
            }
        }
        if(s.size()==0) cout << "EMPTY" << "\n";
        else cout << pq_max.top() << " " << pq_min.top() << "\n";
    }
}