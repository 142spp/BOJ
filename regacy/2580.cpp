#include <iostream>
#include <vector>

using namespace std;

vector<int *> sudoku_orign(9, nullptr);
vector<int> check;
int num_of_zero;

void display_sudoku(vector<int *>);

void dfs_by_horiznal(vector<int *> sudoku, int row)
{
    if (num_of_zero == 0)
        return;
    else
    {
        for (int i = 0; i < 10; i++)
        {
            check[i] = 0;
        }
        for (int i = 0; i < 9; i++)
        {
            check[sudoku[row][i]]++;
            if (sudoku[row][i] != 0 && check[sudoku[row][i]] > 1)
                return;
        }
        for (int i = 0; i < 9; i++)
        {
            if (sudoku[row][i] == 0)
            {
                for (int j = 1; j < 10; j++)
                {
                    if (check[j] == 0)
                    {
                        sudoku[row][i] = j;
                        check[j]++;
                        num_of_zero--;
                        if (i == 8)
                        {
                            if (row == 8)
                            {
                                //dfs_by_vartical(0);
                                printf("\n");
                                display_sudoku(sudoku);
                            }
                            else
                            {
                                dfs_by_horiznal(sudoku, row + 1);
                            }
                        }
                    }
                }
            }
        }
    }
}

void dfs_by_vartical(int col)
{
    if (num_of_zero == 0)
        return;
}

void dfs_by_square(int squ)
{
    if (num_of_zero == 0)
        return;
}

void display_sudoku(vector<int *> sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    num_of_zero = 0;
    for (int i = 0; i < 9; i++)
    {
        sudoku_orign[i] = new int[9];
        for (int j = 0; j < 9; j++)
        {
            int num;
            cin >> num;
            sudoku_orign[i][j] = num;
            if (num == 0)
                num_of_zero++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        check.push_back(0);
    }

    dfs_by_horiznal(sudoku_orign, 0);

    printf("\n");
}