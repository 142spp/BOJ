#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    double h = h1, m = m1, s = s1; 
    while(   (h < h2 )
          || (h==h2&& m<m2)
          || (h==h2&&m==m2&&s<s2)) {
        if(h>=12) { h=0; h2-=12;}
        if(h==0&&m==0&&s==0) { answer++; } 
        else{
            if(h==h2&&m==m2&&s==s2) break;
            if(s <= m+s/60 && s+1 > m+(s+1)/60) { answer++; }
            if(s/5 <= h+m/60+s/3600 && (s+1)/5 > h+m/60+(s+1)/3600) { answer++; }
        }
        s ++;
        if(s>=60) { m++; s=0;}
        if(m>=60) { h++; m=0;}
    }
    if((h==0||h==12)&&m==0&&s==0) { answer++; } 

    return answer;
}