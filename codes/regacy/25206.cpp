#include <bits/stdc++.h>

using namespace std;

map<string,float> s_score = {{"A+",4.5},{"A0",4.0},{"B+",3.5},{"B0",3.0},{"C+",2.5},{"C0",2.0},{"D+",1.5},{"D0",1.0},{"F",0.0}};

int main(){
    string sub; float credit; string score;
    float credit_sum;
    float score_sum;
    while(true){
        cin >> sub >> credit >> score;
        if(cin.eof()) break;
        if(!score.compare("P")) continue;
        credit_sum += credit;
        score_sum += credit * s_score.find(score)->second;
    }
    cout << score_sum / credit_sum ; 
    return 0;
}