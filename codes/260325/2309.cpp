#include <bits/stdc++.h>
using namespace std;

int main(void){
    vector<int> heights(9);
    for(auto& x: heights) cin >> x;
    sort(heights.begin(),heights.end());
    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            int sum = 0;
            for(int k=0; k<9; k++){
                if(k==i || k==j) continue;
                sum += heights[k];
            }
            if(sum == 100){
                for(auto x : heights) {
                    if(x!=heights[i]&&x!=heights[j])cout << x << "\n";}
                return 0;
            }
        }
    }
}