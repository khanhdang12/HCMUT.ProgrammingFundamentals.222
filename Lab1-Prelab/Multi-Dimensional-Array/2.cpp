int diagonalProduct(int arr[][1000], int row, int col) 
{
    int product = 1, i = 0;
    while (i < row)
    {
        product *= arr[i][i];
        i++;
    }
    return product;
}