#include<iostream>
using namespace std;

int* flatten(int** matrix, int r, int c) 
{
    int * arr = new int [r*c];
    int count = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr[count++] = matrix[i][j];
        }
    }
    return arr;
}

int main()
{
    return 0;
}