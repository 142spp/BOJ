#include <bits/stdc++.h>

using namespace std;

struct script{
    int id;
    int priority;
    script(int i, int p){
        this-> id = i;
        this-> priority =p;
    }
    bool operator< (const script &s) const {
        if(this->priority < s.priority) return true;
        else return false;
    }
};

priority_queue<script> pq;
queue<script> q;

int main(){
    int n; cin >> n;
    while(n--){
        while(q.size()>0)  q.pop();
        while(pq.size()>0) pq.pop();
        int N,M, id = 0, count = 1;
        cin >> N >> M;
        while(N--){
            int in_num; cin >> in_num;
            pq.push(script(id,in_num));
            q.push(script(id++,in_num));
        }
        while(q.size()>0){
            if(q.front().priority == pq.top().priority){
                if(q.front().id == M){
                    cout << count << "\n";
                    break;
                } 
                q.pop(); pq.pop();
                count ++;     
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }
    }
}