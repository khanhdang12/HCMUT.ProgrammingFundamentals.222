int findMaxColumn(int arr[][1000], int row, int col) 
{
    int sumhighest = INT_MIN;
    int colhighest = 0;
    for (int j = 0; j < col; j++)
    {
        int sum = 0;
        for (int i = 0; i < row; i++)
        {
            sum += arr[i][j]; 
        }
        
        if (sum >= sumhighest)
        {
            sumhighest = sum;
            colhighest = j;
        }
    }
    return colhighest;
}
