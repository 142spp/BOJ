#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vc;

int main(){
    int n,m;
    long long b;
    cin >> n >> m >> b;
    vc.resize(n,vector<int>(m,0));
    int max_height = 0;
    int min_height = 64000000;
    for(int i =0; i< n; i++){
        for(int j=0; j < m; j++){
            cin >> vc[i][j];
            if(vc[i][j] > max_height) max_height = vc[i][j];
            if(vc[i][j] < min_height) min_height = vc[i][j];
        }
    }
    long long min_time = 64000000*2;
    int correct_height ;
    for(int cur = min_height; cur<=max_height; cur++){
        int cur_item = b;
        int cur_time = 0;
        for(auto i : vc){
            for(auto j : i){
                if(cur < j) {cur_time += 2*(j-cur); cur_item += (j-cur);}
                if(cur > j) {cur_time += 1*(cur-j); cur_item -= (cur-j) ;} 
            }
        }
        if(cur_item < 0) continue;
        if(cur_time < min_time) {
            min_time = cur_time;
            correct_height = cur;
        }
        if(cur_time == min_time){
            if(correct_height < cur) correct_height = cur;
        }
    }
    cout << min_time <<" " << correct_height << endl;
}