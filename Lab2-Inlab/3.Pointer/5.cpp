#include<iostream>
using namespace std;

int** transposeMatrix(int** matrix, int r, int c) 
{
    bool check = false;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] != 0)
            {
                check = true;
                break;
            }
        }
        if (check)
        {
            break;
        }
    }

    if (!check)
    {
        return nullptr;
    }

    int **arr = new int *[c];
    for (int i = 0; i < c; i++)
    {
        arr[i] = new int [r];
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < r; j++)
        {
            arr[i][j] = matrix[j][i];
        }
    }

    return arr;
}

int main()
{
    return 0;
}