#include <bits/stdc++.h>

using namespace std;

int mytype(string in_str){
    int type=0;
    vector<string> tokens{"push","pop","front","back","size","empty"};
    for(string i : tokens){
        if(i==in_str) return type;
        type++;
    }
}

class Queue{
private:
    int* my_array;
    int __size;
    int __max;
    int __front;

public:
    Queue(){
        my_array = new int[1000]();
        __size    = 0;
        __max     = 0;
        __front   = 0;
    }
    void push(int num){
        int get_size = sizeof(my_array)/sizeof(int);
        if(get_size<=__max){
            int* temp_array = new int[get_size*2]();
            for(int i =__front; i <__max-1; i++){
                temp_array[i] = my_array[i];
            }
            delete[] my_array;
            my_array =temp_array; 
        }
        __size++;
        my_array[__max++] = num;
    }
    int pop(){
        if(__size < __front) return -1;
        __size--;
        return my_array[__front++];
    }
    int front(){
        return my_array[__front];
    }
    int back(){
        return my_array[__max-1];
    }
    int size(){
        return __size;
    }
    bool empty(){
        return __size==0;
    }
};

int main(){
    int num;
    cin >> num;
    Queue my_queue = Queue();
    while(num--){
        string order;
        cin >> order;
        int type = mytype(order);
        switch(type){
            case 0: int input; cin >> input; my_queue.push(input); break;
            case 1: cout << my_queue.pop() << "\n"; break;
            case 2: cout << my_queue.front() <<"\n"; break;
            case 3: cout << my_queue.back() << "\n"; break;
            case 4: cout << my_queue.size() << "\n"; break;
            case 5: cout << my_queue.empty() <<"\n"; break;
        }

    }
}