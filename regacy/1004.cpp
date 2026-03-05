#include <iostream>
#include <math.h>

using namespace std;

class planet{

public:
    float x;
    float y;
    float r;
    planet(){};

    planet(int input_x,int input_y, int input_r){
        x= input_x;
        y= input_y;
        r= input_r;
    }
};

bool is_in(planet& plan,float x, float y){
    float distance = sqrt((x-plan.x)*(x-plan.x)+(y-plan.y)*(y-plan.y));
    if(distance > plan.r) return 0;
    else return 1;
}

int main(){
    int num;
    cin >> num;

    for(int i=0; i< num; i++){
        float depart_x, depart_y;
        float final_x, final_y;
        cin >> depart_x >> depart_y >> final_x >> final_y;
        int sum = 0;
        int num_of_planet;
        cin >> num_of_planet;
        planet* planet_list = new planet [num_of_planet];
        for(int j=0; j<num_of_planet; j++){
            cin >> planet_list[j].x >> planet_list[j].y >> planet_list[j].r;
            if(is_in(planet_list[j],depart_x,depart_y)&&!is_in(planet_list[j],final_x,final_y)) sum++;
            else if(!is_in(planet_list[j],depart_x,depart_y)&&is_in(planet_list[j],final_x,final_y)) sum++;
        }
        cout << sum << endl;
    }
}