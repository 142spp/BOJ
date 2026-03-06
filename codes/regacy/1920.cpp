#include <bits/stdc++.h>

using namespace std;

vector<int> nums;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while(n--){
        int num; cin >> num;
        nums.push_back(num);
    }
    sort(nums.begin(),nums.end());

    int m; cin >> m;
    while(m--){
        int num; cin >> num;
        
        int start = 0, end = nums.size();
        int target;
        while(start < end){
            target = (start + end) /2;
            if(nums[target] == num) break;
            if(nums[target] > num){
                end = target;
            }
            else {
                start = target + 1;
            }
        }
        if(start >= end) cout << 0 << "\n";
        else cout << 1 << "\n";
    }
}