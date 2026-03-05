#include <iostream>

using namespace std;

int x_max, y_max;
void printarray(int **);
void cavage(int **array, int i, int j)
{
    //printarray(array);
    array[i][j] = 0;
    if (i == y_max - 1)
    {
        if (array[i - 1][j] == 1)
        {
            cavage(array, i - 1, j);
        }
    }
    else
    {
        if (array[i + 1][j] == 1)
        {
            cavage(array, i + 1, j);
        }
        if (i != 0)
        {
            if (array[i - 1][j] == 1)
            {
                cavage(array, i - 1, j);
            }
        }
    }

    if (j == x_max - 1)
    {
        if (array[i][j - 1] == 1)
        {
            cavage(array, i, j - 1);
        }
    }
    else
    {
        if (array[i][j + 1] == 1)
        {
            cavage(array, i, j + 1);
        }

        if (j != 0)
        {
            if (array[i][j - 1] == 1)
            {
                cavage(array, i, j - 1);
            }
        }
    }
}

void printarray(int **array)
{
    for (int y = 0; y < y_max; y++)
    {
        for (int x = 0; x < x_max; x++)
        {
            cout << array[y][x] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int sum = 0;

        int num_of_cavage;
        cin >> x_max >> y_max >> num_of_cavage;

        
        int** array = new int* [y_max];
        for(int k=0; k<y_max; k++){
            array[k] = new int [x_max]();
        }
        

        for (int j = 0; j < num_of_cavage; j++)
        {
            int x, y;
            cin >> x >> y;
            array[y][x] = 1;
        }
        //cout << "\n";
        //printarray(array);

        for (int y = 0; y < y_max; y++)
        {
            for (int x = 0; x < x_max; x++)
            {
                if (array[y][x] == 1)
                {
                    sum++;
                    cavage(array, y, x);
                }
            }
        }
        cout << sum << endl;

        for (int k = 0; k < y_max; k++)
        {
            delete[] array[k];
        }
        delete[] array;
    }
}