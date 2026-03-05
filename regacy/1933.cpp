#include <iostream>
#define MAXNUM 100000000

using namespace std;

class skyline
{
private:
    int *building;
    int end_;

public:
    skyline(int end_num)
    {
        end_ = end_num;
        building = new int[end_num]();
    }

    void set_building(int x, int v, int h)
    {
        for (int i = x; i < x + h; i++)
        {
            if (building[i] < v)
                building[i] = v;
        }
    }

    void print_skyline()
    {
        for (int i = 0; i < end_; i++)
        {
            printf("%d ", building[i]);
        }
    }

    void print_output()
    {
        int start;
        for (int i = 0; i < end_; i++)
        {
            if (building[i] > 0)
            {
                start = i;
                break;
            }
        }

        printf("%d ", start);
        printf("%d ", building[start]);

        int h = 1, previous = building[start];
        for (int i = start + 1; i < end_; i++)
        {
            if (building[i] == previous)
            {
                h++;
                continue;
            }
            else
            {
                printf("%d ", i);
                printf("%d ", building[i]);
                previous = building[i];
                h = 1;
            }
        }
    }
};

int main()
{
    int num_of_buil;
    cin >> num_of_buil;
    int max_num = 0;
    skyline A = skyline(MAXNUM);
    for (int i = 0; i < num_of_buil; i++)
    {
        int x, v, h;
        cin >> x >> v >> h;
        A.set_building(x, v, h-x);
    }
    A.print_output();
}