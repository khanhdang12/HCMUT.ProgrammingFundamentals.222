void insertRow(int**& matrix, int r, int c, int* rowArr, int row) 
{
    int** newMatrix = new int*[r + 1];
    
    for (int i = 0; i < row; i++) 
    {
        newMatrix[i] = matrix[i];
    }
    
    newMatrix[row] = rowArr;
    
    for (int i = row; i < r; i++) 
    {
        newMatrix[i + 1] = matrix[i];
    }
    
    delete[] matrix;
    matrix = newMatrix;
}
