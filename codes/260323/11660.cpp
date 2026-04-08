#include <bits/stdc++.h>
using namespace std;

int main(void){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n+1,vector<int>(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int c; cin >> c;
            if(j==1) arr[i][j] = c;
            else arr[i][j] = arr[i][j-1] + c;
        }
    }
  while(m--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long sum = 0;
        for(int i=x1; i<=x2; i++){
            sum += arr[i][y2] - arr[i][y1-1];
        }     
        cout << sum << "\n";
    }

}