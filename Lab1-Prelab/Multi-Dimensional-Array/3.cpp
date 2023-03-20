bool isSymmetric(int arr[][1000], int row, int col) 
{
    int flag = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                flag = 1;
            }
        }
    }
    
    if (flag == 1)
    {
        return false;
    }
    
    return true;
}
