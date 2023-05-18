void deleteMatrix(int**& matrix, int r) 
{
    if (matrix != NULL) 
    {
        for (int i = 0; i < r; i++) 
        {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = NULL;
    }
}
