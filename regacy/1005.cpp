#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1000000000

int min_time, win_count;
using namespace std;

struct building{
    vector<building*> link;
    int time;
    bool visited = 0;
};

vector<building*> buildings ;

void print_build(){
    for(auto b : buildings){
        cout << b->time << "\t";
        for(auto l : b->link) cout << l->time << " ";
        cout << "\n";
    }
    
}

void input(){
    int builds, links;
    cin >> builds >> links;
    for(int i=0; i<builds; i++){
        building* b = new building;
        cin >> b->time;
        buildings.push_back(b);
    }
    while(links--){
        int i,j; cin >> i >> j;
        buildings[i]->link.push_back(buildings[j]);
    }
    cin >> win_count;
}

void dfs(int count,int t_time,building* b){
    int time = t_time + b->time;
    b->visited = true;
    if(++count >= win_count) {
        if(time < min_time) min_time = time; return ;
    }
    for(auto i : b->link){
        if(!i->visited){
            dfs(count,time,i);
            i->visited = false;
        }
    }
}

int main(){

    int n; cin >> n;
    while(n--){ 
        min_time = INF;
        buildings.clear();
        buildings.resize(1);
        input();
        dfs(0,0,buildings[1]);
        cout << min_time << "\n";
    }
}