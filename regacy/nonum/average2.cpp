#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int num2;
    float percent[num];
    float **list = new float *[num];

    for (int i = 0; i < num; i++)
    {
        cin >> num2;
        list[i] = new float[num2];

        float sum = 0;
        for (int j = 0; j < num2; j++)
        {
            cin >> list[i][j];
            sum += list[i][j];
        }
        float average = sum / num2;
        int temp = 0;
        for (int k = 0; k < num2; k++)
        {
            if (list[i][k] > average)
                temp++;
        }

        percent[i] = (float)temp / (float)num2;
    }

    for (int i = 0; i < num; i++)
    {
        printf("%.3f",percent[i]*100);
        printf("%%\n");
    }
}